//
// Created by sjh_9 on 22/2/2024.
//
#include "AstFactory.cpp"

class AstProcedures {
public:
    // Zero Nesting Level
    static std::shared_ptr<Procedure> createAssignCallPrintRead() {
        auto procedure = AstFactory::createProcedure("AssignCallPrintRead",
        AstFactory::createStmtList({
            // (1) x = y + 3;
            AstFactory::createAssign(1,
                                     AstFactory::createVariable("x"),
                                     AstFactory::createBinary(
                                             AstFactory::createVariable("y"),
                                             AstFactory::createTokens(TokenType::ADD, "+"),
                                             AstFactory::createLiteral(3)
                                             )),
            // (2) call hello;
            AstFactory::createCall(2, "hello"),
            // (3) print t;
            AstFactory::createRead(3, AstFactory::createVariable("t")),
            // (4) read u;
            AstFactory::createPrint(4, AstFactory::createVariable("u")),
        })
    );
        return procedure;
    }

    static std::shared_ptr<Procedure> createIfElseWithStmtsBeforeAndInside() {
        auto procedure = AstFactory::createProcedure("IfElseWithStmtsBeforeAndInside",
            AstFactory::createStmtList({
                // (1) x = y + 3;
                AstFactory::createAssign(1,
                                         AstFactory::createVariable("x"),
                                         AstFactory::createBinary(
                                                 AstFactory::createVariable("y"),
                                                 AstFactory::createTokens(TokenType::ADD, "+"),
                                                 AstFactory::createLiteral(3))),
                // (2) call hello;
                AstFactory::createCall(2, "hello"),
                // (3) print t;
                AstFactory::createRead(3, AstFactory::createVariable("t")),
                // (4) read u;
                AstFactory::createPrint(4, AstFactory::createVariable("u")),
                // (5) if (x == 1)
                AstFactory::createIf(5,
                    AstFactory::createBinary(
                        AstFactory::createVariable("x"),
                        AstFactory::createTokens(TokenType::EQUAL_EQUAL, "=="),
                        AstFactory::createLiteral(1)
                    ),
                    // then
                    std::make_shared<std::vector<std::shared_ptr<Stmt>>>(
                        std::initializer_list<std::shared_ptr<Stmt>>{
                                // (6) x = y + 3;
                                AstFactory::createAssign(6,
                                                         AstFactory::createVariable("x"),
                                                         AstFactory::createBinary(
                                                                 AstFactory::createVariable("y"),
                                                                 AstFactory::createTokens(TokenType::ADD, "+"),
                                                                 AstFactory::createLiteral(3))),
                                // (7) call hello;
                                AstFactory::createCall(7, "hello"),
                                // (8) print t;
                                AstFactory::createRead(8, AstFactory::createVariable("t")),
                                // (9) read u;
                                AstFactory::createPrint(9, AstFactory::createVariable("u")),
                        }
                    ),
                    // else
                    std::make_shared<std::vector<std::shared_ptr<Stmt>>>(
                        std::initializer_list<std::shared_ptr<Stmt>>{
                                // (10) x = y + 3;
                                AstFactory::createAssign(10,
                                                         AstFactory::createVariable("x"),
                                                         AstFactory::createBinary(
                                                                 AstFactory::createVariable("y"),
                                                                 AstFactory::createTokens(TokenType::ADD, "+"),
                                                                 AstFactory::createLiteral(3))),
                                // (11) call hello;
                                AstFactory::createCall(11, "hello"),
                                // (12) print t;
                                AstFactory::createRead(12, AstFactory::createVariable("t")),
                                // (13) read u;
                                AstFactory::createPrint(13, AstFactory::createVariable("u")),
                        }
                    )
                )
            })
        );
        return procedure;
    }

    // Single Nesting Level
    static std::shared_ptr<Procedure> createIfElseWithStmtsBeforeAfterAndInside() {
        auto procedure = AstFactory::createProcedure("IfElseWithStmtsBeforeAfterAndInside",
            AstFactory::createStmtList({
                // (1) x = y + 3;
                AstFactory::createAssign(1,
                                         AstFactory::createVariable("x"),
                                         AstFactory::createBinary(
                                                 AstFactory::createVariable("y"),
                                                 AstFactory::createTokens(TokenType::ADD, "+"),
                                                 AstFactory::createLiteral(3))),
                // (2) call hello;
                AstFactory::createCall(2, "hello"),
                // (3) print t;
                AstFactory::createRead(3, AstFactory::createVariable("t")),
                // (4) read u;
                AstFactory::createPrint(4, AstFactory::createVariable("u")),
                // (5) if (x == 1)
                AstFactory::createIf(5,
                    AstFactory::createBinary(
                        AstFactory::createVariable("x"),
                        AstFactory::createTokens(TokenType::EQUAL_EQUAL, "=="),
                        AstFactory::createLiteral(1)
                    ),
                    // then
                    std::make_shared<std::vector<std::shared_ptr<Stmt>>>(
                        std::initializer_list<std::shared_ptr<Stmt>>{
                                // (6) x = y + 3;
                                AstFactory::createAssign(6,
                                                         AstFactory::createVariable("x"),
                                                         AstFactory::createBinary(
                                                                 AstFactory::createVariable("y"),
                                                                 AstFactory::createTokens(TokenType::ADD, "+"),
                                                                 AstFactory::createLiteral(3))),
                                // (7) call hello;
                                AstFactory::createCall(7, "hello"),
                                // (8) print t;
                                AstFactory::createRead(8, AstFactory::createVariable("t")),
                                // (9) read u;
                                AstFactory::createPrint(9, AstFactory::createVariable("u")),
                        }
                    ),
                    // else
                    std::make_shared<std::vector<std::shared_ptr<Stmt>>>(
                        std::initializer_list<std::shared_ptr<Stmt>>{
                                // (10) x = y + 3;
                                AstFactory::createAssign(10,
                                                         AstFactory::createVariable("x"),
                                                         AstFactory::createBinary(
                                                                 AstFactory::createVariable("y"),
                                                                 AstFactory::createTokens(TokenType::ADD, "+"),
                                                                 AstFactory::createLiteral(3))),
                                // (11) call hello;
                                AstFactory::createCall(11, "hello"),
                                // (12) print t;
                                AstFactory::createRead(12, AstFactory::createVariable("t")),
                                // (13) read u;
                                AstFactory::createPrint(13, AstFactory::createVariable("u")),
                        }
                    )
                ),
                // (14) x = y + 3;
                AstFactory::createAssign(14,
                                         AstFactory::createVariable("x"),
                                         AstFactory::createBinary(
                                                 AstFactory::createVariable("y"),
                                                 AstFactory::createTokens(TokenType::ADD, "+"),
                                                 AstFactory::createLiteral(3))),
                // (15) call hello;
                AstFactory::createCall(15, "hello"),
                // (16) print t;
                AstFactory::createRead(16, AstFactory::createVariable("t")),
                // (17) read u;
                AstFactory::createPrint(17, AstFactory::createVariable("u")),
            })
        );
        return procedure;
    }

    static std::shared_ptr<Procedure> createIfElseWithStmtsAfterAndInside() {
        auto procedure = AstFactory::createProcedure("IfElseWithStmtsAfterAndInside",
            AstFactory::createStmtList({
                // (1) if (x == 1)
                AstFactory::createIf(1,
                    AstFactory::createBinary(
                        AstFactory::createVariable("x"),
                        AstFactory::createTokens(TokenType::EQUAL_EQUAL, "=="),
                        AstFactory::createLiteral(1)
                    ),
                    // then
                    std::make_shared<std::vector<std::shared_ptr<Stmt>>>(
                        std::initializer_list<std::shared_ptr<Stmt>>{
                                // (2) x = y + 3;
                                AstFactory::createAssign(2,
                                                         AstFactory::createVariable("x"),
                                                         AstFactory::createBinary(
                                                                 AstFactory::createVariable("y"),
                                                                 AstFactory::createTokens(TokenType::ADD, "+"),
                                                                 AstFactory::createLiteral(3))),
                                // (3) call hello;
                                AstFactory::createCall(3, "hello"),
                                // (4) print t;
                                AstFactory::createRead(4, AstFactory::createVariable("t")),
                                // (5) read u;
                                AstFactory::createPrint(5, AstFactory::createVariable("u")),
                        }
                    ),
                    // else
                    std::make_shared<std::vector<std::shared_ptr<Stmt>>>(
                        std::initializer_list<std::shared_ptr<Stmt>>{
                                // (6) x = y + 3;
                                AstFactory::createAssign(6,
                                                         AstFactory::createVariable("x"),
                                                         AstFactory::createBinary(
                                                                 AstFactory::createVariable("y"),
                                                                 AstFactory::createTokens(TokenType::ADD, "+"),
                                                                 AstFactory::createLiteral(3))),
                                // (7) call hello;
                                AstFactory::createCall(7, "hello"),
                                // (8) print t;
                                AstFactory::createRead(8, AstFactory::createVariable("t")),
                                // (9) read u;
                                AstFactory::createPrint(9, AstFactory::createVariable("u")),
                        }
                    )
                ),
                // (10) x = y + 3;
                AstFactory::createAssign(10,
                                         AstFactory::createVariable("x"),
                                         AstFactory::createBinary(
                                                 AstFactory::createVariable("y"),
                                                 AstFactory::createTokens(TokenType::ADD, "+"),
                                                 AstFactory::createLiteral(3))),
                // (11) call hello;
                AstFactory::createCall(11, "hello"),
                // (12) print t;
                AstFactory::createRead(12, AstFactory::createVariable("t")),
                // (13) read u;
                AstFactory::createPrint(13, AstFactory::createVariable("u")),
            })
        );
        return procedure;
    }

    static std::shared_ptr<Procedure> createWhileWithStmtsBeforeAndInside() {
        auto procedure = AstFactory::createProcedure("WhileWithStmtsBeforeAndInside",
            AstFactory::createStmtList({
                // (1) x = y + 3;
                AstFactory::createAssign(1,
                                         AstFactory::createVariable("x"),
                                         AstFactory::createBinary(
                                                 AstFactory::createVariable("y"),
                                                 AstFactory::createTokens(TokenType::ADD, "+"),
                                                 AstFactory::createLiteral(3))),
                // (2) call hello;
                AstFactory::createCall(2, "hello"),
                // (3) print t;
                AstFactory::createRead(3, AstFactory::createVariable("t")),
                // (4) read u;
                AstFactory::createPrint(4, AstFactory::createVariable("u")),
                // (5) While (x == 1)
                AstFactory::createWhile(5,
                    AstFactory::createBinary(
                        AstFactory::createVariable("x"),
                        AstFactory::createTokens(TokenType::EQUAL_EQUAL, "=="),
                        AstFactory::createLiteral(1)
                    ),
                    // body
                    std::make_shared<std::vector<std::shared_ptr<Stmt>>>(
                        std::initializer_list<std::shared_ptr<Stmt>>{
                                // (6) x = y + 3;
                                AstFactory::createAssign(6,
                                                         AstFactory::createVariable("x"),
                                                         AstFactory::createBinary(
                                                                 AstFactory::createVariable("y"),
                                                                 AstFactory::createTokens(TokenType::ADD, "+"),
                                                                 AstFactory::createLiteral(3))),
                                // (7) call hello;
                                AstFactory::createCall(7, "hello"),
                                // (8) print t;
                                AstFactory::createRead(8, AstFactory::createVariable("t")),
                                // (9) read u;
                                AstFactory::createPrint(9, AstFactory::createVariable("u")),
                        }
                    )
                )
            })
        );
        return procedure;
    }

    static std::shared_ptr<Procedure> createWhileWithStmtsBeforeAfterAndInside() {
        auto procedure = AstFactory::createProcedure("WhileWithStmtsBeforeAfterAndInside",
            AstFactory::createStmtList({
                // (1) x = y + 3;
                AstFactory::createAssign(1,
                                         AstFactory::createVariable("x"),
                                         AstFactory::createBinary(
                                                 AstFactory::createVariable("y"),
                                                 AstFactory::createTokens(TokenType::ADD, "+"),
                                                 AstFactory::createLiteral(3))),
                // (2) call hello;
                AstFactory::createCall(2, "hello"),
                // (3) print t;
                AstFactory::createRead(3, AstFactory::createVariable("t")),
                // (4) read u;
                AstFactory::createPrint(4, AstFactory::createVariable("u")),
                // (5) While (x == 1)
                AstFactory::createWhile(5,
                    AstFactory::createBinary(
                        AstFactory::createVariable("x"),
                        AstFactory::createTokens(TokenType::EQUAL_EQUAL, "=="),
                        AstFactory::createLiteral(1)
                    ),
                    // body
                    std::make_shared<std::vector<std::shared_ptr<Stmt>>>(
                        std::initializer_list<std::shared_ptr<Stmt>>{
                                // (6) x = y + 3;
                                AstFactory::createAssign(6,
                                                         AstFactory::createVariable("x"),
                                                         AstFactory::createBinary(
                                                                 AstFactory::createVariable("y"),
                                                                 AstFactory::createTokens(TokenType::ADD, "+"),
                                                                 AstFactory::createLiteral(3))),
                                // (7) call hello;
                                AstFactory::createCall(7, "hello"),
                                // (8) print t;
                                AstFactory::createRead(8, AstFactory::createVariable("t")),
                                // (9) read u;
                                AstFactory::createPrint(9, AstFactory::createVariable("u")),
                        }
                    )
                ),
                // (10) x = y + 3;
                AstFactory::createAssign(10,
                                         AstFactory::createVariable("x"),
                                         AstFactory::createBinary(
                                                 AstFactory::createVariable("y"),
                                                 AstFactory::createTokens(TokenType::ADD, "+"),
                                                 AstFactory::createLiteral(3))),
                // (11) call hello;
                AstFactory::createCall(11, "hello"),
                // (12) print t;
                AstFactory::createRead(12, AstFactory::createVariable("t")),
                // (13) read u;
                AstFactory::createPrint(13, AstFactory::createVariable("u"))
            })
        );
        return procedure;
    }

    static std::shared_ptr<Procedure> createWhileWithStmtsAfterAndInside() {
        auto procedure = AstFactory::createProcedure("WhileWithStmtsAfterAndInside",
            AstFactory::createStmtList({
                // (1) While (x == 1)
                AstFactory::createWhile(1,
                    AstFactory::createBinary(
                        AstFactory::createVariable("x"),
                        AstFactory::createTokens(TokenType::EQUAL_EQUAL, "=="),
                        AstFactory::createLiteral(1)
                    ),
                    // body
                    std::make_shared<std::vector<std::shared_ptr<Stmt>>>(
                        std::initializer_list<std::shared_ptr<Stmt>>{
                                // (2) x = y + 3;
                                AstFactory::createAssign(2,
                                                         AstFactory::createVariable("x"),
                                                         AstFactory::createBinary(
                                                                 AstFactory::createVariable("y"),
                                                                 AstFactory::createTokens(TokenType::ADD, "+"),
                                                                 AstFactory::createLiteral(3))),
                                // (3) call hello;
                                AstFactory::createCall(3, "hello"),
                                // (4) print t;
                                AstFactory::createRead(4, AstFactory::createVariable("t")),
                                // (5) read u;
                                AstFactory::createPrint(5, AstFactory::createVariable("u")),
                        }
                    )
                ),
                // (6) x = y + 3;
                AstFactory::createAssign(6,
                                         AstFactory::createVariable("x"),
                                         AstFactory::createBinary(
                                                 AstFactory::createVariable("y"),
                                                 AstFactory::createTokens(TokenType::ADD, "+"),
                                                 AstFactory::createLiteral(3))),
                // (7) call hello;
                AstFactory::createCall(7, "hello"),
                // (8) print t;
                AstFactory::createRead(8, AstFactory::createVariable("t")),
                // (9) read u;
                AstFactory::createPrint(9, AstFactory::createVariable("u"))
            })
        );
        return procedure;
    }

    // Double Nesting Level

    static std::shared_ptr<Procedure> createIfElseWithNestedIfElsePlusNestedStmtsBeforeAndInside() {
        auto procedure = AstFactory::createProcedure("IfElseWithNestedIfElsePlusNestedStmtsBeforeAndInside",
            AstFactory::createStmtList({
                // (1) if (x == 1)
                AstFactory::createIf(1,
                    AstFactory::createBinary(
                        AstFactory::createVariable("x"),
                        AstFactory::createTokens(TokenType::EQUAL_EQUAL, "=="),
                        AstFactory::createLiteral(1)
                    ),
                    // then
                    std::make_shared<std::vector<std::shared_ptr<Stmt>>>(
                        std::initializer_list<std::shared_ptr<Stmt>>{
                            // (2) x = y + 3;
                            AstFactory::createAssign(2,
                                                     AstFactory::createVariable("x"),
                                                     AstFactory::createBinary(
                                                             AstFactory::createVariable("y"),
                                                             AstFactory::createTokens(TokenType::ADD, "+"),
                                                             AstFactory::createLiteral(3))),
                            // (3) call hello;
                            AstFactory::createCall(3, "hello"),
                            // (4) print t;
                            AstFactory::createRead(4, AstFactory::createVariable("t")),
                            // (5) read u;
                            AstFactory::createPrint(5, AstFactory::createVariable("u")),
                            // (6) if (x == 1)
                            AstFactory::createIf(6,
                                AstFactory::createBinary(
                                    AstFactory::createVariable("x"),
                                    AstFactory::createTokens(TokenType::EQUAL_EQUAL, "=="),
                                    AstFactory::createLiteral(1)
                                ),
                                // then
                                std::make_shared<std::vector<std::shared_ptr<Stmt>>>(
                                    std::initializer_list<std::shared_ptr<Stmt>>{
                                            // (7) x = y + 3;
                                            AstFactory::createAssign(7,
                                                                     AstFactory::createVariable("x"),
                                                                     AstFactory::createBinary(
                                                                             AstFactory::createVariable("y"),
                                                                             AstFactory::createTokens(TokenType::ADD, "+"),
                                                                             AstFactory::createLiteral(3))),
                                            // (8) call hello;
                                            AstFactory::createCall(8, "hello"),
                                            // (9) print t;
                                            AstFactory::createRead(9, AstFactory::createVariable("t")),
                                            // (10) read u;
                                            AstFactory::createPrint(10, AstFactory::createVariable("u")),
                                    }
                                ),
                                // else
                                std::make_shared<std::vector<std::shared_ptr<Stmt>>>(
                                    std::initializer_list<std::shared_ptr<Stmt>>{
                                            // (11) x = y + 3;
                                            AstFactory::createAssign(11,
                                                                     AstFactory::createVariable("x"),
                                                                     AstFactory::createBinary(
                                                                             AstFactory::createVariable("y"),
                                                                             AstFactory::createTokens(TokenType::ADD, "+"),
                                                                             AstFactory::createLiteral(3))),
                                            // (12) call hello;
                                            AstFactory::createCall(12, "hello"),
                                            // (13) print t;
                                            AstFactory::createRead(13, AstFactory::createVariable("t")),
                                            // (14) read u;
                                            AstFactory::createPrint(14, AstFactory::createVariable("u")),
                                    }
                                )
                            )
                        }
                    ),
                    // else
                    std::make_shared<std::vector<std::shared_ptr<Stmt>>>(
                        std::initializer_list<std::shared_ptr<Stmt>>{
                            // (15) x = y + 3;
                            AstFactory::createAssign(15,
                                                     AstFactory::createVariable("x"),
                                                     AstFactory::createBinary(
                                                             AstFactory::createVariable("y"),
                                                             AstFactory::createTokens(TokenType::ADD, "+"),
                                                             AstFactory::createLiteral(3))),
                            // (16) call hello;
                            AstFactory::createCall(16, "hello"),
                            // (17) print t;
                            AstFactory::createRead(17, AstFactory::createVariable("t")),
                            // (18) read u;
                            AstFactory::createPrint(18, AstFactory::createVariable("u")),
                            // (19) if (x == 1)
                            AstFactory::createIf(19,
                                AstFactory::createBinary(
                                    AstFactory::createVariable("x"),
                                    AstFactory::createTokens(TokenType::EQUAL_EQUAL, "=="),
                                    AstFactory::createLiteral(1)
                                ),
                                // then
                                std::make_shared<std::vector<std::shared_ptr<Stmt>>>(
                                    std::initializer_list<std::shared_ptr<Stmt>>{
                                            // (20) x = y + 3;
                                            AstFactory::createAssign(20,
                                                                     AstFactory::createVariable("x"),
                                                                     AstFactory::createBinary(
                                                                             AstFactory::createVariable("y"),
                                                                             AstFactory::createTokens(TokenType::ADD, "+"),
                                                                             AstFactory::createLiteral(3))),
                                            // (21) call hello;
                                            AstFactory::createCall(21, "hello"),
                                            // (22) print t;
                                            AstFactory::createRead(22, AstFactory::createVariable("t")),
                                            // (23) read u;
                                            AstFactory::createPrint(23, AstFactory::createVariable("u")),
                                    }
                                ),
                                // else
                                std::make_shared<std::vector<std::shared_ptr<Stmt>>>(
                                    std::initializer_list<std::shared_ptr<Stmt>>{
                                            // (24) x = y + 3;
                                            AstFactory::createAssign(24,
                                                                     AstFactory::createVariable("x"),
                                                                     AstFactory::createBinary(
                                                                             AstFactory::createVariable("y"),
                                                                             AstFactory::createTokens(TokenType::ADD, "+"),
                                                                             AstFactory::createLiteral(3))),
                                            // (25) call hello;
                                            AstFactory::createCall(25, "hello"),
                                            // (26) print t;
                                            AstFactory::createRead(26, AstFactory::createVariable("t")),
                                            // (27) read u;
                                            AstFactory::createPrint(27, AstFactory::createVariable("u")),
                                    }
                                )
                            )
                        }
                    )
                )
            })
        );
        return procedure;
    }


    static std::shared_ptr<Procedure> createIfElseWithNestedIfElsePlusNestedStmtsBeforeAfterAndInside() {
        auto procedure = AstFactory::createProcedure("IfElseWithNestedIfElsePlusNestedStmtsBeforeAfterAndInside",
            AstFactory::createStmtList({
                // (1) if (x == 1)
                AstFactory::createIf(1,
                    AstFactory::createBinary(
                        AstFactory::createVariable("x"),
                        AstFactory::createTokens(TokenType::EQUAL_EQUAL, "=="),
                        AstFactory::createLiteral(1)
                    ),
                    // then
                    std::make_shared<std::vector<std::shared_ptr<Stmt>>>(
                        std::initializer_list<std::shared_ptr<Stmt>>{
                            // (2) x = y + 3;
                            AstFactory::createAssign(2,
                                                     AstFactory::createVariable("x"),
                                                     AstFactory::createBinary(
                                                             AstFactory::createVariable("y"),
                                                             AstFactory::createTokens(TokenType::ADD, "+"),
                                                             AstFactory::createLiteral(3))),
                            // (3) call hello;
                            AstFactory::createCall(3, "hello"),
                            // (4) print t;
                            AstFactory::createRead(4, AstFactory::createVariable("t")),
                            // (5) read u;
                            AstFactory::createPrint(5, AstFactory::createVariable("u")),
                            // (6) if (x == 1)
                            AstFactory::createIf(6,
                                AstFactory::createBinary(
                                    AstFactory::createVariable("x"),
                                    AstFactory::createTokens(TokenType::EQUAL_EQUAL, "=="),
                                    AstFactory::createLiteral(1)
                                ),
                                // then
                                std::make_shared<std::vector<std::shared_ptr<Stmt>>>(
                                    std::initializer_list<std::shared_ptr<Stmt>>{
                                            // (7) x = y + 3;
                                            AstFactory::createAssign(7,
                                                                     AstFactory::createVariable("x"),
                                                                     AstFactory::createBinary(
                                                                             AstFactory::createVariable("y"),
                                                                             AstFactory::createTokens(TokenType::ADD, "+"),
                                                                             AstFactory::createLiteral(3))),
                                            // (8) call hello;
                                            AstFactory::createCall(8, "hello"),
                                            // (9) print t;
                                            AstFactory::createRead(9, AstFactory::createVariable("t")),
                                            // (10) read u;
                                            AstFactory::createPrint(10, AstFactory::createVariable("u")),
                                    }
                                ),
                                // else
                                std::make_shared<std::vector<std::shared_ptr<Stmt>>>(
                                    std::initializer_list<std::shared_ptr<Stmt>>{
                                            // (11) x = y + 3;
                                            AstFactory::createAssign(11,
                                                                     AstFactory::createVariable("x"),
                                                                     AstFactory::createBinary(
                                                                             AstFactory::createVariable("y"),
                                                                             AstFactory::createTokens(TokenType::ADD, "+"),
                                                                             AstFactory::createLiteral(3))),
                                            // (12) call hello;
                                            AstFactory::createCall(12, "hello"),
                                            // (13) print t;
                                            AstFactory::createRead(13, AstFactory::createVariable("t")),
                                            // (14) read u;
                                            AstFactory::createPrint(14, AstFactory::createVariable("u")),
                                    }
                                )
                            ),
                            // (15) x = y + 3;
                            AstFactory::createAssign(15,
                                                     AstFactory::createVariable("x"),
                                                     AstFactory::createBinary(
                                                             AstFactory::createVariable("y"),
                                                             AstFactory::createTokens(TokenType::ADD, "+"),
                                                             AstFactory::createLiteral(3))),
                            // (16) call hello;
                            AstFactory::createCall(16, "hello"),
                            // (17) print t;
                            AstFactory::createRead(17, AstFactory::createVariable("t")),
                            // (18) read u;
                            AstFactory::createPrint(18, AstFactory::createVariable("u")),

                        }
                    ),
                    // else
                    std::make_shared<std::vector<std::shared_ptr<Stmt>>>(
                        std::initializer_list<std::shared_ptr<Stmt>>{
                            // (19) x = y + 3;
                            AstFactory::createAssign(19,
                                                     AstFactory::createVariable("x"),
                                                     AstFactory::createBinary(
                                                             AstFactory::createVariable("y"),
                                                             AstFactory::createTokens(TokenType::ADD, "+"),
                                                             AstFactory::createLiteral(3))),
                            // (20) call hello;
                            AstFactory::createCall(20, "hello"),
                            // (21) print t;
                            AstFactory::createRead(21, AstFactory::createVariable("t")),
                            // (22) read u;
                            AstFactory::createPrint(22, AstFactory::createVariable("u")),
                            // (23) if (x == 1)
                            AstFactory::createIf(23,
                                AstFactory::createBinary(
                                    AstFactory::createVariable("x"),
                                    AstFactory::createTokens(TokenType::EQUAL_EQUAL, "=="),
                                    AstFactory::createLiteral(1)
                                ),
                                // then
                                std::make_shared<std::vector<std::shared_ptr<Stmt>>>(
                                    std::initializer_list<std::shared_ptr<Stmt>>{
                                            // (24) x = y + 3;
                                            AstFactory::createAssign(24,
                                                                     AstFactory::createVariable("x"),
                                                                     AstFactory::createBinary(
                                                                             AstFactory::createVariable("y"),
                                                                             AstFactory::createTokens(TokenType::ADD, "+"),
                                                                             AstFactory::createLiteral(3))),
                                            // (25) call hello;
                                            AstFactory::createCall(25, "hello"),
                                            // (26) print t;
                                            AstFactory::createRead(26, AstFactory::createVariable("t")),
                                            // (27) read u;
                                            AstFactory::createPrint(27, AstFactory::createVariable("u")),
                                    }
                                ),
                                // else
                                std::make_shared<std::vector<std::shared_ptr<Stmt>>>(
                                    std::initializer_list<std::shared_ptr<Stmt>>{
                                            // (28) x = y + 3;
                                            AstFactory::createAssign(28,
                                                                     AstFactory::createVariable("x"),
                                                                     AstFactory::createBinary(
                                                                             AstFactory::createVariable("y"),
                                                                             AstFactory::createTokens(TokenType::ADD, "+"),
                                                                             AstFactory::createLiteral(3))),
                                            // (29) call hello;
                                            AstFactory::createCall(29, "hello"),
                                            // (30) print t;
                                            AstFactory::createRead(30, AstFactory::createVariable("t")),
                                            // (31) read u;
                                            AstFactory::createPrint(31, AstFactory::createVariable("u")),
                                    }
                                )
                            ),
                            // (32) x = y + 3;
                            AstFactory::createAssign(32,
                                                     AstFactory::createVariable("x"),
                                                     AstFactory::createBinary(
                                                             AstFactory::createVariable("y"),
                                                             AstFactory::createTokens(TokenType::ADD, "+"),
                                                             AstFactory::createLiteral(3))),
                            // (33) call hello;
                            AstFactory::createCall(33, "hello"),
                            // (34) print t;
                            AstFactory::createRead(34, AstFactory::createVariable("t")),
                            // (36) read u;
                            AstFactory::createPrint(35, AstFactory::createVariable("u")),
                        }
                    )
                )
            })
        );
        return procedure;
    }

    static std::shared_ptr<Procedure> createIfElseWithNestedIfElsePlusNestedStmtsAfterAndInside() {
        auto procedure = AstFactory::createProcedure("IfElseWithNestedIfElsePlusNestedStmtsAfterAndInside",
            AstFactory::createStmtList({
                // (1) if (x == 1)
                AstFactory::createIf(1,
                    AstFactory::createBinary(
                        AstFactory::createVariable("x"),
                        AstFactory::createTokens(TokenType::EQUAL_EQUAL, "=="),
                        AstFactory::createLiteral(1)
                    ),
                    // then
                    std::make_shared<std::vector<std::shared_ptr<Stmt>>>(
                        std::initializer_list<std::shared_ptr<Stmt>>{
                            // (2) if (x == 2)
                            AstFactory::createIf(2,
                                AstFactory::createBinary(
                                    AstFactory::createVariable("x"),
                                    AstFactory::createTokens(TokenType::EQUAL_EQUAL, "=="),
                                    AstFactory::createLiteral(1)
                                ),
                                // then
                                std::make_shared<std::vector<std::shared_ptr<Stmt>>>(
                                    std::initializer_list<std::shared_ptr<Stmt>>{
                                            // (3) x = y + 3;
                                            AstFactory::createAssign(3,
                                                                     AstFactory::createVariable("x"),
                                                                     AstFactory::createBinary(
                                                                             AstFactory::createVariable("y"),
                                                                             AstFactory::createTokens(TokenType::ADD, "+"),
                                                                             AstFactory::createLiteral(3))),
                                            // (4) call hello;
                                            AstFactory::createCall(4, "hello"),
                                            // (5) print t;
                                            AstFactory::createRead(5, AstFactory::createVariable("t")),
                                            // (6) read u;
                                            AstFactory::createPrint(6, AstFactory::createVariable("u")),
                                    }
                                ),
                                // else
                                std::make_shared<std::vector<std::shared_ptr<Stmt>>>(
                                    std::initializer_list<std::shared_ptr<Stmt>>{
                                            // (7) x = y + 3;
                                            AstFactory::createAssign(7,
                                                                     AstFactory::createVariable("x"),
                                                                     AstFactory::createBinary(
                                                                             AstFactory::createVariable("y"),
                                                                             AstFactory::createTokens(TokenType::ADD, "+"),
                                                                             AstFactory::createLiteral(3))),
                                            // (8) call hello;
                                            AstFactory::createCall(8, "hello"),
                                            // (9) print t;
                                            AstFactory::createRead(9, AstFactory::createVariable("t")),
                                            // (10) read u;
                                            AstFactory::createPrint(10, AstFactory::createVariable("u")),
                                    }
                                )
                            ),
                            // (11) x = y + 3;
                            AstFactory::createAssign(11,
                                                     AstFactory::createVariable("x"),
                                                     AstFactory::createBinary(
                                                             AstFactory::createVariable("y"),
                                                             AstFactory::createTokens(TokenType::ADD, "+"),
                                                             AstFactory::createLiteral(3))),
                            // (12) call hello;
                            AstFactory::createCall(12, "hello"),
                            // (13) print t;
                            AstFactory::createRead(13, AstFactory::createVariable("t")),
                            // (14) read u;
                            AstFactory::createPrint(14, AstFactory::createVariable("u")),
                        }
                    ),
                    // else
                    std::make_shared<std::vector<std::shared_ptr<Stmt>>>(
                        std::initializer_list<std::shared_ptr<Stmt>>{
                            // (15) if (x == 1)
                            AstFactory::createIf(15,
                                AstFactory::createBinary(
                                    AstFactory::createVariable("x"),
                                    AstFactory::createTokens(TokenType::EQUAL_EQUAL, "=="),
                                    AstFactory::createLiteral(1)
                                ),
                                // then
                                std::make_shared<std::vector<std::shared_ptr<Stmt>>>(
                                    std::initializer_list<std::shared_ptr<Stmt>>{
                                            // (16) x = y + 3;
                                            AstFactory::createAssign(16,
                                                                     AstFactory::createVariable("x"),
                                                                     AstFactory::createBinary(
                                                                             AstFactory::createVariable("y"),
                                                                             AstFactory::createTokens(TokenType::ADD, "+"),
                                                                             AstFactory::createLiteral(3))),
                                            // (17) call hello;
                                            AstFactory::createCall(17, "hello"),
                                            // (18) print t;
                                            AstFactory::createRead(18, AstFactory::createVariable("t")),
                                            // (19) read u;
                                            AstFactory::createPrint(19, AstFactory::createVariable("u")),
                                    }
                                ),
                                // else
                                std::make_shared<std::vector<std::shared_ptr<Stmt>>>(
                                    std::initializer_list<std::shared_ptr<Stmt>>{
                                            // (20) x = y + 3;
                                            AstFactory::createAssign(20,
                                                                     AstFactory::createVariable("x"),
                                                                     AstFactory::createBinary(
                                                                             AstFactory::createVariable("y"),
                                                                             AstFactory::createTokens(TokenType::ADD, "+"),
                                                                             AstFactory::createLiteral(3))),
                                            // (21) call hello;
                                            AstFactory::createCall(21, "hello"),
                                            // (22) print t;
                                            AstFactory::createRead(22, AstFactory::createVariable("t")),
                                            // (23) read u;
                                            AstFactory::createPrint(23, AstFactory::createVariable("u")),
                                    }
                                )
                            ),
                            // (24) x = y + 3;
                            AstFactory::createAssign(24,
                                                     AstFactory::createVariable("x"),
                                                     AstFactory::createBinary(
                                                             AstFactory::createVariable("y"),
                                                             AstFactory::createTokens(TokenType::ADD, "+"),
                                                             AstFactory::createLiteral(3))),
                            // (25) call hello;
                            AstFactory::createCall(25, "hello"),
                            // (26) print t;
                            AstFactory::createRead(26, AstFactory::createVariable("t")),
                            // (27) read u;
                            AstFactory::createPrint(27, AstFactory::createVariable("u")),
                        }
                    )
                )
            })
        );
        return procedure;
    }

    static std::shared_ptr<Procedure> createIfElseWithNestedWhilePlusNestedStmtsBeforeAndInside() {
        auto procedure = AstFactory::createProcedure("IfElseWithNestedWhilePlusNestedStmtsBeforeAndInside",
            AstFactory::createStmtList({
                // (1) if (x == 1)
                AstFactory::createIf(1,
                    AstFactory::createBinary(
                        AstFactory::createVariable("x"),
                        AstFactory::createTokens(TokenType::EQUAL_EQUAL, "=="),
                        AstFactory::createLiteral(1)
                    ),
                    // then
                    std::make_shared<std::vector<std::shared_ptr<Stmt>>>(
                        std::initializer_list<std::shared_ptr<Stmt>>{
                            // (2) x = y + 3;
                            AstFactory::createAssign(2,
                                                     AstFactory::createVariable("x"),
                                                     AstFactory::createBinary(
                                                             AstFactory::createVariable("y"),
                                                             AstFactory::createTokens(TokenType::ADD, "+"),
                                                             AstFactory::createLiteral(3))),
                            // (3) call hello;
                            AstFactory::createCall(3, "hello"),
                            // (4) print t;
                            AstFactory::createRead(4, AstFactory::createVariable("t")),
                            // (5) read u;
                            AstFactory::createPrint(5, AstFactory::createVariable("u")),
                            // (6) While (x == 1)
                            AstFactory::createWhile(6,
                                AstFactory::createBinary(
                                    AstFactory::createVariable("x"),
                                    AstFactory::createTokens(TokenType::EQUAL_EQUAL, "=="),
                                    AstFactory::createLiteral(1)
                                ),
                                // body
                                std::make_shared<std::vector<std::shared_ptr<Stmt>>>(
                                    std::initializer_list<std::shared_ptr<Stmt>>{
                                            // (7) x = y + 3;
                                            AstFactory::createAssign(7,
                                                                     AstFactory::createVariable("x"),
                                                                     AstFactory::createBinary(
                                                                             AstFactory::createVariable("y"),
                                                                             AstFactory::createTokens(TokenType::ADD, "+"),
                                                                             AstFactory::createLiteral(3))),
                                            // (8) call hello;
                                            AstFactory::createCall(8, "hello"),
                                            // (9) print t;
                                            AstFactory::createRead(9, AstFactory::createVariable("t")),
                                            // (10) read u;
                                            AstFactory::createPrint(10, AstFactory::createVariable("u")),
                                    }
                                )
                            )
                        }
                    ),
                    // else
                    std::make_shared<std::vector<std::shared_ptr<Stmt>>>(
                        std::initializer_list<std::shared_ptr<Stmt>>{
                            // (11) x = y + 3;
                            AstFactory::createAssign(11,
                                                     AstFactory::createVariable("x"),
                                                     AstFactory::createBinary(
                                                             AstFactory::createVariable("y"),
                                                             AstFactory::createTokens(TokenType::ADD, "+"),
                                                             AstFactory::createLiteral(3))),
                            // (12) call hello;
                            AstFactory::createCall(12, "hello"),
                            // (13) print t;
                            AstFactory::createRead(13, AstFactory::createVariable("t")),
                            // (14) read u;
                            AstFactory::createPrint(14, AstFactory::createVariable("u")),
                            // (15) While (x == 1)
                            AstFactory::createWhile(15,
                                AstFactory::createBinary(
                                    AstFactory::createVariable("x"),
                                    AstFactory::createTokens(TokenType::EQUAL_EQUAL, "=="),
                                    AstFactory::createLiteral(1)
                                ),
                                // body
                                std::make_shared<std::vector<std::shared_ptr<Stmt>>>(
                                    std::initializer_list<std::shared_ptr<Stmt>>{
                                            // (16) x = y + 3;
                                            AstFactory::createAssign(16,
                                                                     AstFactory::createVariable("x"),
                                                                     AstFactory::createBinary(
                                                                             AstFactory::createVariable("y"),
                                                                             AstFactory::createTokens(TokenType::ADD, "+"),
                                                                             AstFactory::createLiteral(3))),
                                            // (17) call hello;
                                            AstFactory::createCall(17, "hello"),
                                            // (18) print t;
                                            AstFactory::createRead(18, AstFactory::createVariable("t")),
                                            // (19) read u;
                                            AstFactory::createPrint(19, AstFactory::createVariable("u")),
                                    }
                                )
                            )
                        }
                    )
                )
            })
        );
        return procedure;
    }

    static std::shared_ptr<Procedure> createIfElseWithNestedWhilePlusNestedStmtsBeforeAfterAndInside() {
        auto procedure = AstFactory::createProcedure("IfElseWithNestedWhilePlusNestedStmtsBeforeAfterAndInside",
            AstFactory::createStmtList({
                // (1) if (x == 1)
                AstFactory::createIf(1,
                    AstFactory::createBinary(
                        AstFactory::createVariable("x"),
                        AstFactory::createTokens(TokenType::EQUAL_EQUAL, "=="),
                        AstFactory::createLiteral(1)
                    ),
                    // then
                    std::make_shared<std::vector<std::shared_ptr<Stmt>>>(
                        std::initializer_list<std::shared_ptr<Stmt>>{
                            // (2) x = y + 3;
                            AstFactory::createAssign(2,
                                                     AstFactory::createVariable("x"),
                                                     AstFactory::createBinary(
                                                             AstFactory::createVariable("y"),
                                                             AstFactory::createTokens(TokenType::ADD, "+"),
                                                             AstFactory::createLiteral(3))),
                            // (3) call hello;
                            AstFactory::createCall(3, "hello"),
                            // (4) print t;
                            AstFactory::createRead(4, AstFactory::createVariable("t")),
                            // (5) read u;
                            AstFactory::createPrint(5, AstFactory::createVariable("u")),
                            // (6) While (x == 1)
                            AstFactory::createWhile(6,
                                AstFactory::createBinary(
                                    AstFactory::createVariable("x"),
                                    AstFactory::createTokens(TokenType::EQUAL_EQUAL, "=="),
                                    AstFactory::createLiteral(1)
                                ),
                                // body
                                std::make_shared<std::vector<std::shared_ptr<Stmt>>>(
                                    std::initializer_list<std::shared_ptr<Stmt>>{
                                            // (7) x = y + 3;
                                            AstFactory::createAssign(7,
                                                                     AstFactory::createVariable("x"),
                                                                     AstFactory::createBinary(
                                                                             AstFactory::createVariable("y"),
                                                                             AstFactory::createTokens(TokenType::ADD, "+"),
                                                                             AstFactory::createLiteral(3))),
                                            // (8) call hello;
                                            AstFactory::createCall(8, "hello"),
                                            // (9) print t;
                                            AstFactory::createRead(9, AstFactory::createVariable("t")),
                                            // (10) read u;
                                            AstFactory::createPrint(10, AstFactory::createVariable("u")),
                                    }
                                )
                            ),
                            // (11) x = y + 3;
                            AstFactory::createAssign(11,
                                                     AstFactory::createVariable("x"),
                                                     AstFactory::createBinary(
                                                             AstFactory::createVariable("y"),
                                                             AstFactory::createTokens(TokenType::ADD, "+"),
                                                             AstFactory::createLiteral(3))),
                            // (12) call hello;
                            AstFactory::createCall(12, "hello"),
                            // (13) print t;
                            AstFactory::createRead(13, AstFactory::createVariable("t")),
                            // (14) read u;
                            AstFactory::createPrint(14, AstFactory::createVariable("u"))
                        }
                    ),
                    // else
                    std::make_shared<std::vector<std::shared_ptr<Stmt>>>(
                        std::initializer_list<std::shared_ptr<Stmt>>{
                            // (15) x = y + 3;
                            AstFactory::createAssign(15,
                                                     AstFactory::createVariable("x"),
                                                     AstFactory::createBinary(
                                                             AstFactory::createVariable("y"),
                                                             AstFactory::createTokens(TokenType::ADD, "+"),
                                                             AstFactory::createLiteral(3))),
                            // (16) call hello;
                            AstFactory::createCall(16, "hello"),
                            // (17) print t;
                            AstFactory::createRead(17, AstFactory::createVariable("t")),
                            // (18) read u;
                            AstFactory::createPrint(18, AstFactory::createVariable("u")),
                            // (19) While (x == 1)
                            AstFactory::createWhile(19,
                                AstFactory::createBinary(
                                    AstFactory::createVariable("x"),
                                    AstFactory::createTokens(TokenType::EQUAL_EQUAL, "=="),
                                    AstFactory::createLiteral(1)
                                ),
                                // body
                                std::make_shared<std::vector<std::shared_ptr<Stmt>>>(
                                    std::initializer_list<std::shared_ptr<Stmt>>{
                                            // (20) x = y + 3;
                                            AstFactory::createAssign(20,
                                                                     AstFactory::createVariable("x"),
                                                                     AstFactory::createBinary(
                                                                             AstFactory::createVariable("y"),
                                                                             AstFactory::createTokens(TokenType::ADD, "+"),
                                                                             AstFactory::createLiteral(3))),
                                            // (21) call hello;
                                            AstFactory::createCall(21, "hello"),
                                            // (22) print t;
                                            AstFactory::createRead(22, AstFactory::createVariable("t")),
                                            // (23) read u;
                                            AstFactory::createPrint(23, AstFactory::createVariable("u")),
                                    }
                                )
                            ),
                            // (24) x = y + 3;
                            AstFactory::createAssign(24,
                                                     AstFactory::createVariable("x"),
                                                     AstFactory::createBinary(
                                                             AstFactory::createVariable("y"),
                                                             AstFactory::createTokens(TokenType::ADD, "+"),
                                                             AstFactory::createLiteral(3))),
                            // (25) call hello;
                            AstFactory::createCall(25, "hello"),
                            // (26) print t;
                            AstFactory::createRead(26, AstFactory::createVariable("t")),
                            // (27) read u;
                            AstFactory::createPrint(27, AstFactory::createVariable("u"))
                        }
                    )
                )
            })
        );
        return procedure;
    }

    static std::shared_ptr<Procedure> createIfElseWithNestedWhilePlusNestedStmtsAfterAndInside() {
        auto procedure = AstFactory::createProcedure("IfElseWithNestedWhilePlusNestedStmtsAfterAndInside",
            AstFactory::createStmtList({
                // (1) if (x == 1)
                AstFactory::createIf(1,
                    AstFactory::createBinary(
                        AstFactory::createVariable("x"),
                        AstFactory::createTokens(TokenType::EQUAL_EQUAL, "=="),
                        AstFactory::createLiteral(1)
                    ),
                    // then
                    std::make_shared<std::vector<std::shared_ptr<Stmt>>>(
                        std::initializer_list<std::shared_ptr<Stmt>>{
                            // (2) While (x == 1)
                            AstFactory::createWhile(2,
                                AstFactory::createBinary(
                                    AstFactory::createVariable("x"),
                                    AstFactory::createTokens(TokenType::EQUAL_EQUAL, "=="),
                                    AstFactory::createLiteral(1)
                                ),
                                // body
                                std::make_shared<std::vector<std::shared_ptr<Stmt>>>(
                                    std::initializer_list<std::shared_ptr<Stmt>>{
                                            // (3) x = y + 3;
                                            AstFactory::createAssign(3,
                                                                     AstFactory::createVariable("x"),
                                                                     AstFactory::createBinary(
                                                                             AstFactory::createVariable("y"),
                                                                             AstFactory::createTokens(TokenType::ADD, "+"),
                                                                             AstFactory::createLiteral(3))),
                                            // (4) call hello;
                                            AstFactory::createCall(4, "hello"),
                                            // (5) print t;
                                            AstFactory::createRead(5, AstFactory::createVariable("t")),
                                            // (6) read u;
                                            AstFactory::createPrint(6, AstFactory::createVariable("u")),
                                    }
                                )
                            ),
                            // (7) x = y + 3;
                            AstFactory::createAssign(7,
                                                     AstFactory::createVariable("x"),
                                                     AstFactory::createBinary(
                                                             AstFactory::createVariable("y"),
                                                             AstFactory::createTokens(TokenType::ADD, "+"),
                                                             AstFactory::createLiteral(3))),
                            // (8) call hello;
                            AstFactory::createCall(8, "hello"),
                            // (9) print t;
                            AstFactory::createRead(9, AstFactory::createVariable("t")),
                            // (10) read u;
                            AstFactory::createPrint(10, AstFactory::createVariable("u"))
                        }
                    ),
                    // else
                    std::make_shared<std::vector<std::shared_ptr<Stmt>>>(
                        std::initializer_list<std::shared_ptr<Stmt>>{
                            // (11) While (x == 1)
                            AstFactory::createWhile(11,
                                AstFactory::createBinary(
                                    AstFactory::createVariable("x"),
                                    AstFactory::createTokens(TokenType::EQUAL_EQUAL, "=="),
                                    AstFactory::createLiteral(1)
                                ),
                                // body
                                std::make_shared<std::vector<std::shared_ptr<Stmt>>>(
                                    std::initializer_list<std::shared_ptr<Stmt>>{
                                            // (12) x = y + 3;
                                            AstFactory::createAssign(12,
                                                                     AstFactory::createVariable("x"),
                                                                     AstFactory::createBinary(
                                                                             AstFactory::createVariable("y"),
                                                                             AstFactory::createTokens(TokenType::ADD, "+"),
                                                                             AstFactory::createLiteral(3))),
                                            // (13) call hello;
                                            AstFactory::createCall(13, "hello"),
                                            // (14) print t;
                                            AstFactory::createRead(14, AstFactory::createVariable("t")),
                                            // (15) read u;
                                            AstFactory::createPrint(15, AstFactory::createVariable("u")),
                                    }
                                )
                            ),
                            // (16) x = y + 3;
                            AstFactory::createAssign(16,
                                                     AstFactory::createVariable("x"),
                                                     AstFactory::createBinary(
                                                             AstFactory::createVariable("y"),
                                                             AstFactory::createTokens(TokenType::ADD, "+"),
                                                             AstFactory::createLiteral(3))),
                            // (17) call hello;
                            AstFactory::createCall(17, "hello"),
                            // (18) print t;
                            AstFactory::createRead(18, AstFactory::createVariable("t")),
                            // (19) read u;
                            AstFactory::createPrint(19, AstFactory::createVariable("u"))
                        }
                    )
                )
            })
        );
        return procedure;
    }

    static std::shared_ptr<Procedure> createWhileWithNestedIfElsePlusNestedStmtsBeforeAndInside() {
        auto procedure = AstFactory::createProcedure("WhileWithNestedIfElsePlusNestedStmtsBeforeAndInside",
            AstFactory::createStmtList({
                // (1) While (x == 1)
                AstFactory::createWhile(1,
                    AstFactory::createBinary(
                        AstFactory::createVariable("x"),
                        AstFactory::createTokens(TokenType::EQUAL_EQUAL, "=="),
                        AstFactory::createLiteral(1)
                    ),
                    // body
                    std::make_shared<std::vector<std::shared_ptr<Stmt>>>(
                        std::initializer_list<std::shared_ptr<Stmt>>{
                            // (2) x = y + 3;
                            AstFactory::createAssign(2,
                                                     AstFactory::createVariable("x"),
                                                     AstFactory::createBinary(
                                                             AstFactory::createVariable("y"),
                                                             AstFactory::createTokens(TokenType::ADD, "+"),
                                                             AstFactory::createLiteral(3))),
                            // (3) call hello;
                            AstFactory::createCall(3, "hello"),
                            // (4) print t;
                            AstFactory::createRead(4, AstFactory::createVariable("t")),
                            // (5) read u;
                            AstFactory::createPrint(5, AstFactory::createVariable("u")),
                            // (6) if (x == 1)
                            AstFactory::createIf(6,
                                AstFactory::createBinary(
                                    AstFactory::createVariable("x"),
                                    AstFactory::createTokens(TokenType::EQUAL_EQUAL, "=="),
                                    AstFactory::createLiteral(1)
                                ),
                                // then
                                std::make_shared<std::vector<std::shared_ptr<Stmt>>>(
                                    std::initializer_list<std::shared_ptr<Stmt>>{
                                            // (7) x = y + 3;
                                            AstFactory::createAssign(7,
                                                                     AstFactory::createVariable("x"),
                                                                     AstFactory::createBinary(
                                                                             AstFactory::createVariable("y"),
                                                                             AstFactory::createTokens(TokenType::ADD, "+"),
                                                                             AstFactory::createLiteral(3))),
                                            // (8) call hello;
                                            AstFactory::createCall(8, "hello"),
                                            // (9) print t;
                                            AstFactory::createRead(9, AstFactory::createVariable("t")),
                                            // (10) read u;
                                            AstFactory::createPrint(10, AstFactory::createVariable("u")),
                                    }
                                ),
                                // else
                                std::make_shared<std::vector<std::shared_ptr<Stmt>>>(
                                    std::initializer_list<std::shared_ptr<Stmt>>{
                                            // (11) x = y + 3;
                                            AstFactory::createAssign(11,
                                                                     AstFactory::createVariable("x"),
                                                                     AstFactory::createBinary(
                                                                             AstFactory::createVariable("y"),
                                                                             AstFactory::createTokens(TokenType::ADD, "+"),
                                                                             AstFactory::createLiteral(3))),
                                            // (12) call hello;
                                            AstFactory::createCall(12, "hello"),
                                            // (13) print t;
                                            AstFactory::createRead(13, AstFactory::createVariable("t")),
                                            // (14) read u;
                                            AstFactory::createPrint(14, AstFactory::createVariable("u")),
                                    }
                                )
                            )
                        }
                    )
                )
            })
        );
        return procedure;
    }

    static std::shared_ptr<Procedure> createWhileWithNestedIfElsePlusNestedStmtsBeforeAfterAndInside() {
        auto procedure = AstFactory::createProcedure("WhileWithNestedIfElsePlusNestedStmtsBeforeAfterAndInside",
            AstFactory::createStmtList({
                // (1) While (x == 1)
                AstFactory::createWhile(1,
                    AstFactory::createBinary(
                        AstFactory::createVariable("x"),
                        AstFactory::createTokens(TokenType::EQUAL_EQUAL, "=="),
                        AstFactory::createLiteral(1)
                    ),
                    // body
                    std::make_shared<std::vector<std::shared_ptr<Stmt>>>(
                        std::initializer_list<std::shared_ptr<Stmt>>{
                            // (2) x = y + 3;
                            AstFactory::createAssign(2,
                                                     AstFactory::createVariable("x"),
                                                     AstFactory::createBinary(
                                                             AstFactory::createVariable("y"),
                                                             AstFactory::createTokens(TokenType::ADD, "+"),
                                                             AstFactory::createLiteral(3))),
                            // (3) call hello;
                            AstFactory::createCall(3, "hello"),
                            // (4) print t;
                            AstFactory::createRead(4, AstFactory::createVariable("t")),
                            // (5) read u;
                            AstFactory::createPrint(5, AstFactory::createVariable("u")),
                            // (6) if (x == 1)
                            AstFactory::createIf(6,
                                AstFactory::createBinary(
                                    AstFactory::createVariable("x"),
                                    AstFactory::createTokens(TokenType::EQUAL_EQUAL, "=="),
                                    AstFactory::createLiteral(1)
                                ),
                                // then
                                std::make_shared<std::vector<std::shared_ptr<Stmt>>>(
                                    std::initializer_list<std::shared_ptr<Stmt>>{
                                            // (7) x = y + 3;
                                            AstFactory::createAssign(7,
                                                                     AstFactory::createVariable("x"),
                                                                     AstFactory::createBinary(
                                                                             AstFactory::createVariable("y"),
                                                                             AstFactory::createTokens(TokenType::ADD, "+"),
                                                                             AstFactory::createLiteral(3))),
                                            // (8) call hello;
                                            AstFactory::createCall(8, "hello"),
                                            // (9) print t;
                                            AstFactory::createRead(9, AstFactory::createVariable("t")),
                                            // (10) read u;
                                            AstFactory::createPrint(10, AstFactory::createVariable("u")),
                                    }
                                ),
                                // else
                                std::make_shared<std::vector<std::shared_ptr<Stmt>>>(
                                    std::initializer_list<std::shared_ptr<Stmt>>{
                                            // (11) x = y + 3;
                                            AstFactory::createAssign(11,
                                                                     AstFactory::createVariable("x"),
                                                                     AstFactory::createBinary(
                                                                             AstFactory::createVariable("y"),
                                                                             AstFactory::createTokens(TokenType::ADD, "+"),
                                                                             AstFactory::createLiteral(3))),
                                            // (12) call hello;
                                            AstFactory::createCall(12, "hello"),
                                            // (13) print t;
                                            AstFactory::createRead(13, AstFactory::createVariable("t")),
                                            // (14) read u;
                                            AstFactory::createPrint(14, AstFactory::createVariable("u")),
                                    }
                                )
                            ),
                            // (15) x = y + 3;
                            AstFactory::createAssign(15,
                                                     AstFactory::createVariable("x"),
                                                     AstFactory::createBinary(
                                                             AstFactory::createVariable("y"),
                                                             AstFactory::createTokens(TokenType::ADD, "+"),
                                                             AstFactory::createLiteral(3))),
                            // (16) call hello;
                            AstFactory::createCall(16, "hello"),
                            // (17) print t;
                            AstFactory::createRead(17, AstFactory::createVariable("t")),
                            // (18) read u;
                            AstFactory::createPrint(18, AstFactory::createVariable("u")),
                        }
                    )
                )
            })
        );
        return procedure;
    }

    static std::shared_ptr<Procedure> createWhileWithNestedIfElsePlusNestedStmtsAfterAndInside() {
        auto procedure = AstFactory::createProcedure("WhileWithNestedIfElsePlusNestedStmtsAfterAndInside",
                AstFactory::createStmtList({
                    // (1) While (x == 1)
                    AstFactory::createWhile(1,
                        AstFactory::createBinary(
                            AstFactory::createVariable("x"),
                            AstFactory::createTokens(TokenType::EQUAL_EQUAL, "=="),
                            AstFactory::createLiteral(1)
                        ),
                        // body
                        std::make_shared<std::vector<std::shared_ptr<Stmt>>>(
                            std::initializer_list<std::shared_ptr<Stmt>>{
                                // (2) if (x == 1)
                                AstFactory::createIf(2,
                                    AstFactory::createBinary(
                                        AstFactory::createVariable("x"),
                                        AstFactory::createTokens(TokenType::EQUAL_EQUAL, "=="),
                                        AstFactory::createLiteral(1)
                                    ),
                                    // then
                                    std::make_shared<std::vector<std::shared_ptr<Stmt>>>(
                                        std::initializer_list<std::shared_ptr<Stmt>>{
                                                // (3) x = y + 3;
                                                AstFactory::createAssign(3,
                                                                         AstFactory::createVariable("x"),
                                                                         AstFactory::createBinary(
                                                                                 AstFactory::createVariable("y"),
                                                                                 AstFactory::createTokens(TokenType::ADD, "+"),
                                                                                 AstFactory::createLiteral(3))),
                                                // (4) call hello;
                                                AstFactory::createCall(4, "hello"),
                                                // (5) print t;
                                                AstFactory::createRead(5, AstFactory::createVariable("t")),
                                                // (6) read u;
                                                AstFactory::createPrint(6, AstFactory::createVariable("u")),
                                        }
                                    ),
                                    // else
                                    std::make_shared<std::vector<std::shared_ptr<Stmt>>>(
                                        std::initializer_list<std::shared_ptr<Stmt>>{
                                                // (7) x = y + 3;
                                                AstFactory::createAssign(7,
                                                                         AstFactory::createVariable("x"),
                                                                         AstFactory::createBinary(
                                                                                 AstFactory::createVariable("y"),
                                                                                 AstFactory::createTokens(TokenType::ADD, "+"),
                                                                                 AstFactory::createLiteral(3))),
                                                // (8) call hello;
                                                AstFactory::createCall(8, "hello"),
                                                // (9) print t;
                                                AstFactory::createRead(9, AstFactory::createVariable("t")),
                                                // (10) read u;
                                                AstFactory::createPrint(10, AstFactory::createVariable("u")),
                                        }
                                    )
                                ),
                                // (11) x = y + 3;
                                AstFactory::createAssign(11,
                                                         AstFactory::createVariable("x"),
                                                         AstFactory::createBinary(
                                                                 AstFactory::createVariable("y"),
                                                                 AstFactory::createTokens(TokenType::ADD, "+"),
                                                                 AstFactory::createLiteral(3))),
                                // (12) call hello;
                                AstFactory::createCall(12, "hello"),
                                // (13) print t;
                                AstFactory::createRead(13, AstFactory::createVariable("t")),
                                // (14) read u;
                                AstFactory::createPrint(14, AstFactory::createVariable("u")),
                            }
                        )
                    )
                })
            );
        return procedure;
    }

    static std::shared_ptr<Procedure> createWhileWithNestedWhilePlusNestedStmtsBeforeAndInside() {
        auto procedure = AstFactory::createProcedure("WhileWithNestedWhilePlusNestedStmtsBeforeAndInside",
            AstFactory::createStmtList({
                // (1) While (x == 1)
                AstFactory::createWhile(1,
                    AstFactory::createBinary(
                        AstFactory::createVariable("x"),
                        AstFactory::createTokens(TokenType::EQUAL_EQUAL, "=="),
                        AstFactory::createLiteral(1)
                    ),
                    // body
                    std::make_shared<std::vector<std::shared_ptr<Stmt>>>(
                        std::initializer_list<std::shared_ptr<Stmt>>{
                            // (2) x = y + 3;
                            AstFactory::createAssign(2,
                                                     AstFactory::createVariable("x"),
                                                     AstFactory::createBinary(
                                                             AstFactory::createVariable("y"),
                                                             AstFactory::createTokens(TokenType::ADD, "+"),
                                                             AstFactory::createLiteral(3))),
                            // (3) call hello;
                            AstFactory::createCall(3, "hello"),
                            // (4) print t;
                            AstFactory::createRead(4, AstFactory::createVariable("t")),
                            // (5) read u;
                            AstFactory::createPrint(5, AstFactory::createVariable("u")),
                            // (6) While (x == 1)
                            AstFactory::createWhile(6,
                                AstFactory::createBinary(
                                    AstFactory::createVariable("x"),
                                    AstFactory::createTokens(TokenType::EQUAL_EQUAL, "=="),
                                    AstFactory::createLiteral(1)
                                ),
                                // body
                                std::make_shared<std::vector<std::shared_ptr<Stmt>>>(
                                    std::initializer_list<std::shared_ptr<Stmt>>{
                                            // (7) x = y + 3;
                                            AstFactory::createAssign(7,
                                                                     AstFactory::createVariable("x"),
                                                                     AstFactory::createBinary(
                                                                             AstFactory::createVariable("y"),
                                                                             AstFactory::createTokens(TokenType::ADD, "+"),
                                                                             AstFactory::createLiteral(3))),
                                            // (8) call hello;
                                            AstFactory::createCall(8, "hello"),
                                            // (9) print t;
                                            AstFactory::createRead(9, AstFactory::createVariable("t")),
                                            // (10) read u;
                                            AstFactory::createPrint(10, AstFactory::createVariable("u")),
                                    }
                                )
                            )
                        }
                    )
                )
            })
        );
        return procedure;
    }

    static std::shared_ptr<Procedure> createWhileWithNestedWhilePlusNestedStmtsBeforeAfterAndInside() {
        auto procedure = AstFactory::createProcedure("WhileWithNestedWhilePlusNestedStmtsBeforeAfterAndInside",
            AstFactory::createStmtList({
                // (1) While (x == 1)
                AstFactory::createWhile(1,
                    AstFactory::createBinary(
                        AstFactory::createVariable("x"),
                        AstFactory::createTokens(TokenType::EQUAL_EQUAL, "=="),
                        AstFactory::createLiteral(1)
                    ),
                    // body
                    std::make_shared<std::vector<std::shared_ptr<Stmt>>>(
                        std::initializer_list<std::shared_ptr<Stmt>>{
                            // (2) x = y + 3;
                            AstFactory::createAssign(2,
                                                     AstFactory::createVariable("x"),
                                                     AstFactory::createBinary(
                                                             AstFactory::createVariable("y"),
                                                             AstFactory::createTokens(TokenType::ADD, "+"),
                                                             AstFactory::createLiteral(3))),
                            // (3) call hello;
                            AstFactory::createCall(3, "hello"),
                            // (4) print t;
                            AstFactory::createRead(4, AstFactory::createVariable("t")),
                            // (5) read u;
                            AstFactory::createPrint(5, AstFactory::createVariable("u")),
                            // (6) While (x == 1)
                            AstFactory::createWhile(6,
                                AstFactory::createBinary(
                                    AstFactory::createVariable("x"),
                                    AstFactory::createTokens(TokenType::EQUAL_EQUAL, "=="),
                                    AstFactory::createLiteral(1)
                                ),
                                // body
                                std::make_shared<std::vector<std::shared_ptr<Stmt>>>(
                                    std::initializer_list<std::shared_ptr<Stmt>>{
                                            // (7) x = y + 3;
                                            AstFactory::createAssign(7,
                                                                     AstFactory::createVariable("x"),
                                                                     AstFactory::createBinary(
                                                                             AstFactory::createVariable("y"),
                                                                             AstFactory::createTokens(TokenType::ADD, "+"),
                                                                             AstFactory::createLiteral(3))),
                                            // (8) call hello;
                                            AstFactory::createCall(8, "hello"),
                                            // (9) print t;
                                            AstFactory::createRead(9, AstFactory::createVariable("t")),
                                            // (10) read u;
                                            AstFactory::createPrint(10, AstFactory::createVariable("u")),
                                    }
                                )
                            ),
                            // (11) x = y + 3;
                            AstFactory::createAssign(11,
                                                     AstFactory::createVariable("x"),
                                                     AstFactory::createBinary(
                                                             AstFactory::createVariable("y"),
                                                             AstFactory::createTokens(TokenType::ADD, "+"),
                                                             AstFactory::createLiteral(3))),
                            // (12) call hello;
                            AstFactory::createCall(12, "hello"),
                            // (13) print t;
                            AstFactory::createRead(13, AstFactory::createVariable("t")),
                            // (14) read u;
                            AstFactory::createPrint(14, AstFactory::createVariable("u"))
                        }
                    )
                )
            })
        );
        return procedure;
    }

    static std::shared_ptr<Procedure> createWhileWithNestedWhilePlusNestedStmtsAfterAndInside() {
        auto procedure = AstFactory::createProcedure("WhileWithNestedWhilePlusNestedStmtsAfterAndInside",
            AstFactory::createStmtList({
                // (1) While (x == 1)
                AstFactory::createWhile(1,
                    AstFactory::createBinary(
                        AstFactory::createVariable("x"),
                        AstFactory::createTokens(TokenType::EQUAL_EQUAL, "=="),
                        AstFactory::createLiteral(1)
                    ),
                    // body
                    std::make_shared<std::vector<std::shared_ptr<Stmt>>>(
                        std::initializer_list<std::shared_ptr<Stmt>>{
                            // (2) While (x == 1)
                            AstFactory::createWhile(2,
                                AstFactory::createBinary(
                                    AstFactory::createVariable("x"),
                                    AstFactory::createTokens(TokenType::EQUAL_EQUAL, "=="),
                                    AstFactory::createLiteral(1)
                                ),
                                // body
                                std::make_shared<std::vector<std::shared_ptr<Stmt>>>(
                                    std::initializer_list<std::shared_ptr<Stmt>>{
                                            // (3) x = y + 3;
                                            AstFactory::createAssign(3,
                                                                     AstFactory::createVariable("x"),
                                                                     AstFactory::createBinary(
                                                                             AstFactory::createVariable("y"),
                                                                             AstFactory::createTokens(TokenType::ADD, "+"),
                                                                             AstFactory::createLiteral(3))),
                                            // (4) call hello;
                                            AstFactory::createCall(4, "hello"),
                                            // (5) print t;
                                            AstFactory::createRead(5, AstFactory::createVariable("t")),
                                            // (6) read u;
                                            AstFactory::createPrint(6, AstFactory::createVariable("u")),
                                    }
                                )
                            ),
                            // (7) x = y + 3;
                            AstFactory::createAssign(7,
                                                     AstFactory::createVariable("x"),
                                                     AstFactory::createBinary(
                                                             AstFactory::createVariable("y"),
                                                             AstFactory::createTokens(TokenType::ADD, "+"),
                                                             AstFactory::createLiteral(3))),
                            // (8) call hello;
                            AstFactory::createCall(8, "hello"),
                            // (9) print t;
                            AstFactory::createRead(9, AstFactory::createVariable("t")),
                            // (10) read u;
                            AstFactory::createPrint(10, AstFactory::createVariable("u"))
                        }
                    )
                )
            })
        );
        return procedure;
    }
};