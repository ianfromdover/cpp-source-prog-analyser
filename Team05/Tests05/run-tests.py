import argparse
import os
import xml.etree.ElementTree as ET
import zipfile
import shutil

parser = argparse.ArgumentParser(
    prog='System Test Runner',
    description='Runs a series of system tests against the autotester',
    epilog='')
parser.add_argument('-e', '--executable', help='location of autotester executable')
parser.add_argument('-d', '--directory', help='directory containing tests')

args = parser.parse_args()

pass_run_summary = []
fail_run_summary = []


def locate_exe():
    path1 = os.path.abspath(
        os.path.join(os.pardir, 'Code05/cmake-build-debug-visual-studio/src/autotester/autotester.exe'))
    path2 = os.path.abspath(os.path.join(os.pardir, 'Code05/cmake-cli/src/autotester/Debug/autotester.exe'))

    if os.path.exists(path1):
        if not args.executable:
            args.executable = path1
            pass
    if os.path.exists(path2):
        if not args.executable:
            args.executable = path2
            pass
    pass


def get_txt_files(input_path):
    files = []
    search_dir = os.path.abspath(os.path.join(input_path, 'testcases'))
    for file in os.listdir(search_dir):
        if file.endswith(".txt"):
            files.append(os.path.join(search_dir, file))
    return files


def configure_test_files(txt_files):
    test_cases = []

    sorted_files = sorted(txt_files)

    for i in range(int(len(txt_files) / 2)):
        source = sorted_files[2 * i + 1]
        query = sorted_files[2 * i]
        results = os.path.join(os.path.abspath(os.path.join(query, os.path.pardir, os.path.pardir, 'results')),
                               os.path.basename(query)[:os.path.basename(query).rfind('queries.txt')] + 'results.xml')

        if (source.find('source') == -1 or query.find('queries') == -1):
            raise 'error: file not found!'

        test_cases.append([source, query, results])

    print(test_cases)
    return test_cases


def execute_test(exe_path, test_case):
    query_path = '"' + test_case[1] + '"'
    source_path = '"' + test_case[0] + '"'
    result_path = '"' + test_case[2] + '"'
    exe_path1 = r'"' + os.path.abspath(exe_path) + r'"'

    # print(f"Executing: {exe_path1} {source_path} {query_path} {result_path}")
    cmd = f'{exe_path1} {source_path} {query_path} {result_path}'
    os.system('"' + cmd + '"')
    process_results(test_case[2])


def process_results(xml_file):
    print(f"Processing: {xml_file}")
    # Parse the XML file
    tree = ET.parse(xml_file)
    root = tree.getroot()

    # Iterate over the query elements
    for query in root.findall('queries/query'):
        query_id = query.find('id').text
        failed_element = query.find('failed')
        pass_element = query.find('passed')

        # If the query has a failed element, print the details
        if failed_element is not None:
            querystr = query.find('querystr').text
            print(f"Failed - Query String: {querystr}")
            add_result(False, querystr, xml_file)

        elif pass_element is not None:
            querystr = query.find('querystr').text
            print(f"Passed - Query String: {querystr}")
            add_result(True, querystr, xml_file)


def add_result(passed, querystr, result_file):
    global pass_run_summary
    global fail_run_summary

    if passed:
        pass_run_summary.append([querystr, result_file])
    else:
        fail_run_summary.append([querystr, result_file])


def print_summary():
    global pass_run_summary
    global fail_run_summary
    print('Summary:')

    if len(fail_run_summary) > 0:
        for result in fail_run_summary:
            print(f"  {result[0]} - {result[1]}")
    else:
        print('  All tests passed')


def clean_dir(dir):
    for file in os.listdir(dir):
        if file.endswith(".xml"):
            os.remove(os.path.join(dir, file))
    pass


def check_dir():
    if not args.directory:
        args.directory = '.'
    pass


def zip_results(path):
    zip_file_path = os.path.join(path, 'results.zip')

    with zipfile.ZipFile(zip_file_path, 'w') as zipf:
        for file in os.listdir(path):
            if file.endswith(".xml"):
                zipf.write(os.path.join(path, file), file)


def check_results():
    pass


def main():
    locate_exe()
    # clean_dir(os.path.join('.', 'results'))
    check_dir()
    print(args.executable)
    for test_case in configure_test_files(get_txt_files(args.directory)):
        execute_test(args.executable, test_case)
    # process_results('test.xml')
    print_summary()
    zip_results(os.path.join('.', 'results'))
    exit(len(fail_run_summary))
    pass


if __name__ == '__main__':
    main()
