//
// Created by Chua Bing Quan on 21/3/24.
//

#include "TokenizedTestProgramProducer.h"

std::shared_ptr<TokenStream> TokenizedTestProgramProducer::createAssignCallPrintRead() const {
    return TokenFactory::createProgram({
        TokenFactory::createProcedure("AssignCallPrintRead", {
            TokenFactory::createAssign("t", TokenFactory::createAddExpr(
                TokenFactory::createMultiplyExpr(
                    TokenFactory::createGrouping(TokenFactory::createAddExpr(
                        TokenFactory::createInt(1),
                        TokenFactory::createVariable("y")
                    )),
                    TokenFactory::createInt(3)
                ),
                TokenFactory::createVariable("y")
            )),
            TokenFactory::createCall("hello"),
            TokenFactory::createRead("t"),
            TokenFactory::createPrint("u"),
        })
    });
}

std::shared_ptr<TokenStream> TokenizedTestProgramProducer::createIfElseWithStmtsBeforeAndInside() const {
    return TokenFactory::createProgram({
        TokenFactory::createProcedure("IfElseWithStmtsBeforeAndInside", {
            TokenFactory::createAssign("x", TokenFactory::createAddExpr(
                TokenFactory::createVariable("y"),
                TokenFactory::createInt(3)
            )),
            TokenFactory::createCall("hello"),
            TokenFactory::createRead("t"),
            TokenFactory::createPrint("u"),
            TokenFactory::createIf(
                TokenFactory::createEqualsExpr(TokenFactory::createVariable("x"), TokenFactory::createInt(1)),
                {
                    TokenFactory::createAssign("t", TokenFactory::createAddExpr(
                        TokenFactory::createMultiplyExpr(
                            TokenFactory::createGrouping(TokenFactory::createAddExpr(
                                TokenFactory::createInt(1),
                                TokenFactory::createVariable("y")
                            )),
                            TokenFactory::createInt(3)
                        ),
                        TokenFactory::createVariable("y")
                    )),
                    TokenFactory::createCall("hello"),
                    TokenFactory::createRead("t"),
                    TokenFactory::createPrint("u"),
                },
                {
                    TokenFactory::createAssign("x", TokenFactory::createAddExpr(
                        TokenFactory::createVariable("y"),
                        TokenFactory::createInt(3)
                    )),
                    TokenFactory::createCall("hello"),
                    TokenFactory::createRead("t"),
                    TokenFactory::createPrint("u"),
                }
            ),
        })
    });
}

std::shared_ptr<TokenStream> TokenizedTestProgramProducer::createIfElseWithStmtsBeforeAfterAndInside() const {
    return TokenFactory::createProgram({
        TokenFactory::createProcedure("IfElseWithStmtsBeforeAfterAndInside", {
            TokenFactory::createAssign("x", TokenFactory::createAddExpr(
                TokenFactory::createVariable("y"),
                TokenFactory::createInt(3)
            )),
            TokenFactory::createCall("hello"),
            TokenFactory::createRead("t"),
            TokenFactory::createPrint("u"),
            TokenFactory::createIf(
                TokenFactory::createEqualsExpr(TokenFactory::createVariable("x"), TokenFactory::createInt(1)),
                {
                    TokenFactory::createAssign("x", TokenFactory::createAddExpr(
                        TokenFactory::createVariable("y"),
                        TokenFactory::createInt(3)
                    )),
                    TokenFactory::createCall("hello"),
                    TokenFactory::createRead("t"),
                    TokenFactory::createPrint("u"),
                },
                {
                    TokenFactory::createAssign("x", TokenFactory::createAddExpr(
                        TokenFactory::createVariable("y"),
                        TokenFactory::createInt(3)
                    )),
                    TokenFactory::createCall("hello"),
                    TokenFactory::createRead("t"),
                    TokenFactory::createPrint("u"),
                }
            ),
            TokenFactory::createAssign("x", TokenFactory::createAddExpr(
                TokenFactory::createVariable("y"),
                TokenFactory::createInt(3)
            )),
            TokenFactory::createCall("hello"),
            TokenFactory::createRead("t"),
            TokenFactory::createPrint("u"),
        })
    });
}

std::shared_ptr<TokenStream> TokenizedTestProgramProducer::createIfElseWithStmtsAfterAndInside() const {
    return TokenFactory::createProgram({
        TokenFactory::createProcedure("IfElseWithStmtsAfterAndInside", {
            TokenFactory::createIf(
                TokenFactory::createEqualsExpr(TokenFactory::createVariable("x"), TokenFactory::createInt(1)),
                {
                    TokenFactory::createAssign("x", TokenFactory::createAddExpr(
                        TokenFactory::createVariable("y"),
                        TokenFactory::createInt(3)
                    )),
                    TokenFactory::createCall("hello"),
                    TokenFactory::createRead("t"),
                    TokenFactory::createPrint("u"),
                },
                {
                    TokenFactory::createAssign("x", TokenFactory::createAddExpr(
                        TokenFactory::createVariable("y"),
                        TokenFactory::createInt(3)
                    )),
                    TokenFactory::createCall("hello"),
                    TokenFactory::createRead("t"),
                    TokenFactory::createPrint("u"),
                }
            ),
            TokenFactory::createAssign("x", TokenFactory::createAddExpr(
                TokenFactory::createVariable("y"),
                TokenFactory::createInt(3)
            )),
            TokenFactory::createCall("hello"),
            TokenFactory::createRead("t"),
            TokenFactory::createPrint("u"),
        })
    });
}

std::shared_ptr<TokenStream> TokenizedTestProgramProducer::createWhileWithStmtsBeforeAndInside() const {
    return TokenFactory::createProgram({
        TokenFactory::createProcedure("WhileWithStmtsBeforeAndInside", {
            TokenFactory::createAssign("x", TokenFactory::createAddExpr(
                TokenFactory::createVariable("y"),
                TokenFactory::createInt(3)
            )),
            TokenFactory::createCall("hello"),
            TokenFactory::createRead("t"),
            TokenFactory::createPrint("u"),
            TokenFactory::createWhile(
                TokenFactory::createEqualsExpr(TokenFactory::createVariable("x"), TokenFactory::createInt(1)),
                {
                    TokenFactory::createAssign("x", TokenFactory::createAddExpr(
                        TokenFactory::createVariable("y"),
                        TokenFactory::createInt(3)
                    )),
                    TokenFactory::createCall("hello"),
                    TokenFactory::createRead("t"),
                    TokenFactory::createPrint("u"),
                }
            ),
        })
    });
}

std::shared_ptr<TokenStream> TokenizedTestProgramProducer::createWhileWithStmtsBeforeAfterAndInside() const {
    return TokenFactory::createProgram({
        TokenFactory::createProcedure("WhileWithStmtsBeforeAfterAndInside", {
            TokenFactory::createAssign("x", TokenFactory::createAddExpr(
                TokenFactory::createVariable("y"),
                TokenFactory::createInt(3)
            )),
            TokenFactory::createCall("hello"),
            TokenFactory::createRead("t"),
            TokenFactory::createPrint("u"),
            TokenFactory::createWhile(
                TokenFactory::createEqualsExpr(TokenFactory::createVariable("x"), TokenFactory::createInt(1)),
                {
                    TokenFactory::createAssign("x", TokenFactory::createAddExpr(
                        TokenFactory::createVariable("y"),
                        TokenFactory::createInt(3)
                    )),
                    TokenFactory::createCall("hello"),
                    TokenFactory::createRead("t"),
                    TokenFactory::createPrint("u"),
                }
            ),
            TokenFactory::createAssign("x", TokenFactory::createAddExpr(
                TokenFactory::createVariable("y"),
                TokenFactory::createInt(3)
            )),
            TokenFactory::createCall("hello"),
            TokenFactory::createRead("t"),
            TokenFactory::createPrint("u"),
        })
    });
}

std::shared_ptr<TokenStream> TokenizedTestProgramProducer::createWhileWithStmtsAfterAndInside() const {
    return TokenFactory::createProgram({
        TokenFactory::createProcedure("WhileWithStmtsAfterAndInside", {
            TokenFactory::createWhile(
                TokenFactory::createEqualsExpr(TokenFactory::createVariable("x"), TokenFactory::createInt(1)),
                {
                    TokenFactory::createAssign("x", TokenFactory::createAddExpr(
                        TokenFactory::createVariable("y"),
                        TokenFactory::createInt(3)
                    )),
                    TokenFactory::createCall("hello"),
                    TokenFactory::createRead("t"),
                    TokenFactory::createPrint("u"),
                }
            ),
            TokenFactory::createAssign("x", TokenFactory::createAddExpr(
                TokenFactory::createVariable("y"),
                TokenFactory::createInt(3)
            )),
            TokenFactory::createCall("hello"),
            TokenFactory::createRead("t"),
            TokenFactory::createPrint("u"),
        })
    });
}

std::shared_ptr<TokenStream> TokenizedTestProgramProducer::createIfElseWithNestedIfElsePlusNestedStmtsBeforeAndInside() const {
    return TokenFactory::createProgram({
        TokenFactory::createProcedure("IfElseWithNestedIfElsePlusNestedStmtsBeforeAndInside", {
            TokenFactory::createIf(
                TokenFactory::createEqualsExpr(TokenFactory::createVariable("x"),TokenFactory::createInt(1)),
                {
                    TokenFactory::createAssign("x", TokenFactory::createAddExpr(
                        TokenFactory::createVariable("y"),
                        TokenFactory::createInt(3)
                    )),
                    TokenFactory::createCall("hello"),
                    TokenFactory::createRead("t"),
                    TokenFactory::createPrint("u"),
                    TokenFactory::createIf(
                        TokenFactory::createEqualsExpr(TokenFactory::createVariable("x"), TokenFactory::createInt(1)),
                        {
                            TokenFactory::createAssign("t", TokenFactory::createAddExpr(
                                TokenFactory::createMultiplyExpr(
                                    TokenFactory::createGrouping(TokenFactory::createAddExpr(
                                        TokenFactory::createInt(1),
                                        TokenFactory::createVariable("y")
                                    )),
                                    TokenFactory::createInt(3)
                                ),
                                TokenFactory::createVariable("y")
                            )),
                            TokenFactory::createCall("hello"),
                            TokenFactory::createRead("t"),
                            TokenFactory::createPrint("u"),
                        },
                        {
                            TokenFactory::createAssign("x", TokenFactory::createAddExpr(
                                TokenFactory::createVariable("y"),
                                TokenFactory::createInt(3)
                            )),
                            TokenFactory::createCall("hello"),
                            TokenFactory::createRead("t"),
                            TokenFactory::createPrint("u"),
                        }
                    ),
                },
                {
                    TokenFactory::createAssign("x", TokenFactory::createAddExpr(
                        TokenFactory::createVariable("y"),
                        TokenFactory::createInt(3)
                    )),
                    TokenFactory::createCall("hello"),
                    TokenFactory::createRead("t"),
                    TokenFactory::createPrint("u"),
                    TokenFactory::createIf(
                        TokenFactory::createEqualsExpr(TokenFactory::createVariable("x"), TokenFactory::createInt(1)),
                        {
                            TokenFactory::createAssign("x", TokenFactory::createAddExpr(
                                TokenFactory::createVariable("y"),
                                TokenFactory::createInt(3)
                            )),
                            TokenFactory::createCall("hello"),
                            TokenFactory::createRead("t"),
                            TokenFactory::createPrint("u"),
                        },
                        {
                            TokenFactory::createAssign("x", TokenFactory::createAddExpr(
                                TokenFactory::createVariable("y"),
                                TokenFactory::createInt(3)
                            )),
                            TokenFactory::createCall("hello"),
                            TokenFactory::createRead("t"),
                            TokenFactory::createPrint("u"),
                        }
                    ),
                }
            ),
        })
    });
}

std::shared_ptr<TokenStream> TokenizedTestProgramProducer::createIfElseWithNestedIfElsePlusNestedStmtsBeforeAfterAndInside() const {
    return TokenFactory::createProgram({
        TokenFactory::createProcedure("IfElseWithNestedIfElsePlusNestedStmtsBeforeAfterAndInside", {
            TokenFactory::createIf(
                TokenFactory::createEqualsExpr(TokenFactory::createVariable("x"),TokenFactory::createInt(1)),
                {
                    TokenFactory::createAssign("x", TokenFactory::createAddExpr(
                        TokenFactory::createVariable("y"),
                        TokenFactory::createInt(3)
                    )),
                    TokenFactory::createCall("hello"),
                    TokenFactory::createRead("t"),
                    TokenFactory::createPrint("u"),
                    TokenFactory::createIf(
                        TokenFactory::createEqualsExpr(TokenFactory::createVariable("x"), TokenFactory::createInt(1)),
                        {
                            TokenFactory::createAssign("x", TokenFactory::createAddExpr(
                                TokenFactory::createVariable("y"),
                                TokenFactory::createInt(3)
                            )),
                            TokenFactory::createCall("hello"),
                            TokenFactory::createRead("t"),
                            TokenFactory::createPrint("u"),
                        },
                        {
                            TokenFactory::createAssign("x", TokenFactory::createAddExpr(
                                TokenFactory::createVariable("y"),
                                TokenFactory::createInt(3)
                            )),
                            TokenFactory::createCall("hello"),
                            TokenFactory::createRead("t"),
                            TokenFactory::createPrint("u"),
                        }
                    ),
                    TokenFactory::createAssign("x", TokenFactory::createAddExpr(
                        TokenFactory::createVariable("y"),
                        TokenFactory::createInt(3)
                    )),
                    TokenFactory::createCall("hello"),
                    TokenFactory::createRead("t"),
                    TokenFactory::createPrint("u"),
                },
                {
                    TokenFactory::createAssign("x", TokenFactory::createAddExpr(
                        TokenFactory::createVariable("y"),
                        TokenFactory::createInt(3)
                    )),
                    TokenFactory::createCall("hello"),
                    TokenFactory::createRead("t"),
                    TokenFactory::createPrint("u"),
                    TokenFactory::createIf(
                        TokenFactory::createEqualsExpr(TokenFactory::createVariable("x"), TokenFactory::createInt(1)),
                        {
                            TokenFactory::createAssign("x", TokenFactory::createAddExpr(
                                TokenFactory::createVariable("y"),
                                TokenFactory::createInt(3)
                            )),
                            TokenFactory::createCall("hello"),
                            TokenFactory::createRead("t"),
                            TokenFactory::createPrint("u"),
                        },
                        {
                            TokenFactory::createAssign("x", TokenFactory::createAddExpr(
                                TokenFactory::createVariable("y"),
                                TokenFactory::createInt(3)
                            )),
                            TokenFactory::createCall("hello"),
                            TokenFactory::createRead("t"),
                            TokenFactory::createPrint("u"),
                        }
                    ),
                    TokenFactory::createAssign("x", TokenFactory::createAddExpr(
                        TokenFactory::createVariable("y"),
                        TokenFactory::createInt(3)
                    )),
                    TokenFactory::createCall("hello"),
                    TokenFactory::createRead("t"),
                    TokenFactory::createPrint("u"),
                }
            ),
        })
    });
}

std::shared_ptr<TokenStream> TokenizedTestProgramProducer::createIfElseWithNestedIfElsePlusNestedStmtsAfterAndInside() const {
    return TokenFactory::createProgram({
        TokenFactory::createProcedure("IfElseWithNestedIfElsePlusNestedStmtsAfterAndInside", {
            TokenFactory::createIf(
                TokenFactory::createEqualsExpr(TokenFactory::createVariable("x"), TokenFactory::createInt(1)),
                {
                    TokenFactory::createIf(
                        TokenFactory::createEqualsExpr(TokenFactory::createVariable("x"), TokenFactory::createInt(1)),
                        {
                            TokenFactory::createAssign("x", TokenFactory::createAddExpr(
                                TokenFactory::createVariable("y"),
                                TokenFactory::createInt(3)
                            )),
                            TokenFactory::createCall("hello"),
                            TokenFactory::createRead("t"),
                            TokenFactory::createPrint("u"),
                        },
                        {
                            TokenFactory::createAssign("x", TokenFactory::createAddExpr(
                                TokenFactory::createVariable("y"),
                                TokenFactory::createInt(3)
                            )),
                            TokenFactory::createCall("hello"),
                            TokenFactory::createRead("t"),
                            TokenFactory::createPrint("u"),
                        }
                    ),
                    TokenFactory::createAssign("x", TokenFactory::createAddExpr(
                        TokenFactory::createVariable("y"),
                        TokenFactory::createInt(3)
                    )),
                    TokenFactory::createCall("hello"),
                    TokenFactory::createRead("t"),
                    TokenFactory::createPrint("u"),
                },
                {
                    TokenFactory::createIf(
                        TokenFactory::createEqualsExpr(TokenFactory::createVariable("x"), TokenFactory::createInt(1)),
                        {
                            TokenFactory::createAssign("x", TokenFactory::createAddExpr(
                                TokenFactory::createVariable("y"),
                                TokenFactory::createInt(3)
                            )),
                            TokenFactory::createCall("hello"),
                            TokenFactory::createRead("t"),
                            TokenFactory::createPrint("u"),
                        },
                        {
                            TokenFactory::createAssign("x", TokenFactory::createAddExpr(
                                TokenFactory::createVariable("y"),
                                TokenFactory::createInt(3)
                            )),
                            TokenFactory::createCall("hello"),
                            TokenFactory::createRead("t"),
                            TokenFactory::createPrint("u"),
                        }
                    ),
                    TokenFactory::createAssign("x", TokenFactory::createAddExpr(
                        TokenFactory::createVariable("y"),
                        TokenFactory::createInt(3)
                    )),
                    TokenFactory::createCall("hello"),
                    TokenFactory::createRead("t"),
                    TokenFactory::createPrint("u"),
                }
            ),
        })
    });
}

std::shared_ptr<TokenStream> TokenizedTestProgramProducer::createIfElseWithNestedWhilePlusNestedStmtsBeforeAndInside() const {
    return TokenFactory::createProgram({
        TokenFactory::createProcedure("IfElseWithNestedWhilePlusNestedStmtsBeforeAndInside", {
            TokenFactory::createIf(
                TokenFactory::createEqualsExpr(TokenFactory::createVariable("x"), TokenFactory::createInt(1)),
                {
                    TokenFactory::createAssign("x", TokenFactory::createAddExpr(
                        TokenFactory::createVariable("y"),
                        TokenFactory::createInt(3)
                    )),
                    TokenFactory::createCall("hello"),
                    TokenFactory::createRead("t"),
                    TokenFactory::createPrint("u"),
                    TokenFactory::createWhile(
                        TokenFactory::createEqualsExpr(TokenFactory::createVariable("x"), TokenFactory::createInt(1)),
                        {
                            TokenFactory::createAssign("x", TokenFactory::createAddExpr(
                                TokenFactory::createVariable("y"),
                                TokenFactory::createInt(3)
                            )),
                            TokenFactory::createCall("hello"),
                            TokenFactory::createRead("t"),
                            TokenFactory::createPrint("u"),
                        }
                    ),
                },
                {
                    TokenFactory::createAssign("x", TokenFactory::createAddExpr(
                        TokenFactory::createVariable("y"),
                        TokenFactory::createInt(3)
                    )),
                    TokenFactory::createCall("hello"),
                    TokenFactory::createRead("t"),
                    TokenFactory::createPrint("u"),
                    TokenFactory::createWhile(
                        TokenFactory::createEqualsExpr(TokenFactory::createVariable("x"), TokenFactory::createInt(1)),
                        {
                            TokenFactory::createAssign("x", TokenFactory::createAddExpr(
                                TokenFactory::createVariable("y"),
                                TokenFactory::createInt(3)
                            )),
                            TokenFactory::createCall("hello"),
                            TokenFactory::createRead("t"),
                            TokenFactory::createPrint("u"),
                        }
                    ),
                }
            ),
        })
    });
}

std::shared_ptr<TokenStream> TokenizedTestProgramProducer::createIfElseWithNestedWhilePlusNestedStmtsBeforeAfterAndInside() const {
    return TokenFactory::createProgram({
        TokenFactory::createProcedure("IfElseWithNestedWhilePlusNestedStmtsBeforeAfterAndInside", {
            TokenFactory::createIf(
                TokenFactory::createEqualsExpr(TokenFactory::createVariable("x"), TokenFactory::createInt(1)),
                {
                    TokenFactory::createAssign("x", TokenFactory::createAddExpr(
                        TokenFactory::createVariable("y"),
                        TokenFactory::createInt(3)
                    )),
                    TokenFactory::createCall("hello"),
                    TokenFactory::createRead("t"),
                    TokenFactory::createPrint("u"),
                    TokenFactory::createWhile(
                        TokenFactory::createEqualsExpr(TokenFactory::createVariable("x"), TokenFactory::createInt(1)),
                        {
                            TokenFactory::createAssign("x", TokenFactory::createAddExpr(
                                TokenFactory::createVariable("y"),
                                TokenFactory::createInt(3)
                            )),
                            TokenFactory::createCall("hello"),
                            TokenFactory::createRead("t"),
                            TokenFactory::createPrint("u"),
                        }
                    ),
                    TokenFactory::createAssign("x", TokenFactory::createAddExpr(
                        TokenFactory::createVariable("y"),
                        TokenFactory::createInt(3)
                    )),
                    TokenFactory::createCall("hello"),
                    TokenFactory::createRead("t"),
                    TokenFactory::createPrint("u"),
                },
                {
                    TokenFactory::createAssign("x", TokenFactory::createAddExpr(
                        TokenFactory::createVariable("y"),
                        TokenFactory::createInt(3)
                    )),
                    TokenFactory::createCall("hello"),
                    TokenFactory::createRead("t"),
                    TokenFactory::createPrint("u"),
                    TokenFactory::createWhile(
                        TokenFactory::createEqualsExpr(TokenFactory::createVariable("x"), TokenFactory::createInt(1)),
                        {
                            TokenFactory::createAssign("x", TokenFactory::createAddExpr(
                                TokenFactory::createVariable("y"),
                                TokenFactory::createInt(3)
                            )),
                            TokenFactory::createCall("hello"),
                            TokenFactory::createRead("t"),
                            TokenFactory::createPrint("u"),
                        }
                    ),
                    TokenFactory::createAssign("x", TokenFactory::createAddExpr(
                        TokenFactory::createVariable("y"),
                        TokenFactory::createInt(3)
                    )),
                    TokenFactory::createCall("hello"),
                    TokenFactory::createRead("t"),
                    TokenFactory::createPrint("u"),
                }
            ),
        })
    });
}

std::shared_ptr<TokenStream> TokenizedTestProgramProducer::createIfElseWithNestedWhilePlusNestedStmtsAfterAndInside() const {
    return TokenFactory::createProgram({
        TokenFactory::createProcedure("IfElseWithNestedWhilePlusNestedStmtsAfterAndInside", {
            TokenFactory::createIf(
                TokenFactory::createEqualsExpr(TokenFactory::createVariable("x"), TokenFactory::createInt(1)),
                {
                    TokenFactory::createWhile(
                        TokenFactory::createEqualsExpr(TokenFactory::createVariable("x"), TokenFactory::createInt(1)),
                        {
                            TokenFactory::createAssign("x", TokenFactory::createAddExpr(
                                TokenFactory::createVariable("y"),
                                TokenFactory::createInt(3)
                            )),
                            TokenFactory::createCall("hello"),
                            TokenFactory::createRead("t"),
                            TokenFactory::createPrint("u"),
                        }
                    ),
                    TokenFactory::createAssign("x", TokenFactory::createAddExpr(
                        TokenFactory::createVariable("y"),
                        TokenFactory::createInt(3)
                    )),
                    TokenFactory::createCall("hello"),
                    TokenFactory::createRead("t"),
                    TokenFactory::createPrint("u"),
                },
                {
                    TokenFactory::createWhile(
                        TokenFactory::createEqualsExpr(TokenFactory::createVariable("x"), TokenFactory::createInt(1)),
                        {
                            TokenFactory::createAssign("x", TokenFactory::createAddExpr(
                                TokenFactory::createVariable("y"),
                                TokenFactory::createInt(3)
                            )),
                            TokenFactory::createCall("hello"),
                            TokenFactory::createRead("t"),
                            TokenFactory::createPrint("u"),
                        }
                    ),
                    TokenFactory::createAssign("x", TokenFactory::createAddExpr(
                        TokenFactory::createVariable("y"),
                        TokenFactory::createInt(3)
                    )),
                    TokenFactory::createCall("hello"),
                    TokenFactory::createRead("t"),
                    TokenFactory::createPrint("u"),
                }
            ),
        })
    });
}

std::shared_ptr<TokenStream> TokenizedTestProgramProducer::createWhileWithNestedIfElsePlusNestedStmtsBeforeAndInside() const {
    return TokenFactory::createProgram({
        TokenFactory::createProcedure("WhileWithNestedIfElsePlusNestedStmtsBeforeAndInside", {
            TokenFactory::createWhile(
                TokenFactory::createEqualsExpr(TokenFactory::createVariable("x"), TokenFactory::createInt(1)),
                {
                    TokenFactory::createAssign("x", TokenFactory::createAddExpr(
                        TokenFactory::createVariable("y"),
                        TokenFactory::createInt(3)
                    )),
                    TokenFactory::createCall("hello"),
                    TokenFactory::createRead("t"),
                    TokenFactory::createPrint("u"),
                    TokenFactory::createIf(
                        TokenFactory::createEqualsExpr(TokenFactory::createVariable("x"), TokenFactory::createInt(1)),
                        {
                            TokenFactory::createAssign("x", TokenFactory::createAddExpr(
                                TokenFactory::createVariable("y"),
                                TokenFactory::createInt(3)
                            )),
                            TokenFactory::createCall("hello"),
                            TokenFactory::createRead("t"),
                            TokenFactory::createPrint("u"),
                        },
                        {
                            TokenFactory::createAssign("x", TokenFactory::createAddExpr(
                                TokenFactory::createVariable("y"),
                                TokenFactory::createInt(3)
                            )),
                            TokenFactory::createCall("hello"),
                            TokenFactory::createRead("t"),
                            TokenFactory::createPrint("u"),
                        }
                    ),
                }
            ),
        })
    });
}

std::shared_ptr<TokenStream> TokenizedTestProgramProducer::createWhileWithNestedIfElsePlusNestedStmtsBeforeAfterAndInside() const {
    return TokenFactory::createProgram({
        TokenFactory::createProcedure("WhileWithNestedIfElsePlusNestedStmtsBeforeAfterAndInside", {
            TokenFactory::createWhile(
                TokenFactory::createEqualsExpr(TokenFactory::createVariable("x"), TokenFactory::createInt(1)),
                {
                    TokenFactory::createAssign("x", TokenFactory::createAddExpr(
                        TokenFactory::createVariable("y"),
                        TokenFactory::createInt(3)
                    )),
                    TokenFactory::createCall("hello"),
                    TokenFactory::createRead("t"),
                    TokenFactory::createPrint("u"),
                    TokenFactory::createIf(
                        TokenFactory::createEqualsExpr(TokenFactory::createVariable("x"), TokenFactory::createInt(1)),
                        {
                            TokenFactory::createAssign("x", TokenFactory::createAddExpr(
                                TokenFactory::createVariable("y"),
                                TokenFactory::createInt(3)
                            )),
                            TokenFactory::createCall("hello"),
                            TokenFactory::createRead("t"),
                            TokenFactory::createPrint("u"),
                        },
                        {
                            TokenFactory::createAssign("x", TokenFactory::createAddExpr(
                                TokenFactory::createVariable("y"),
                                TokenFactory::createInt(3)
                            )),
                            TokenFactory::createCall("hello"),
                            TokenFactory::createRead("t"),
                            TokenFactory::createPrint("u"),
                        }
                    ),
                    TokenFactory::createAssign("x", TokenFactory::createAddExpr(
                        TokenFactory::createVariable("y"),
                        TokenFactory::createInt(3)
                    )),
                    TokenFactory::createCall("hello"),
                    TokenFactory::createRead("t"),
                    TokenFactory::createPrint("u"),
                }
            ),
        })
    });
}

std::shared_ptr<TokenStream> TokenizedTestProgramProducer::createWhileWithNestedIfElsePlusNestedStmtsAfterAndInside() const {
    return TokenFactory::createProgram({
        TokenFactory::createProcedure("WhileWithNestedIfElsePlusNestedStmtsAfterAndInside", {
            TokenFactory::createWhile(
                TokenFactory::createEqualsExpr(TokenFactory::createVariable("x"), TokenFactory::createInt(1)),
                {
                    TokenFactory::createIf(
                        TokenFactory::createEqualsExpr(TokenFactory::createVariable("x"), TokenFactory::createInt(1)),
                        {
                            TokenFactory::createAssign("x", TokenFactory::createAddExpr(
                                TokenFactory::createVariable("y"),
                                TokenFactory::createInt(3)
                            )),
                            TokenFactory::createCall("hello"),
                            TokenFactory::createRead("t"),
                            TokenFactory::createPrint("u"),
                        },
                        {
                            TokenFactory::createAssign("x", TokenFactory::createAddExpr(
                                TokenFactory::createVariable("y"),
                                TokenFactory::createInt(3)
                            )),
                            TokenFactory::createCall("hello"),
                            TokenFactory::createRead("t"),
                            TokenFactory::createPrint("u"),
                        }
                    ),
                    TokenFactory::createAssign("x", TokenFactory::createAddExpr(
                        TokenFactory::createVariable("y"),
                        TokenFactory::createInt(3)
                    )),
                    TokenFactory::createCall("hello"),
                    TokenFactory::createRead("t"),
                    TokenFactory::createPrint("u"),
                }
            ),
        })
    });
}

std::shared_ptr<TokenStream> TokenizedTestProgramProducer::createWhileWithNestedWhilePlusNestedStmtsBeforeAndInside() const {
    return TokenFactory::createProgram({
        TokenFactory::createProcedure("WhileWithNestedWhilePlusNestedStmtsBeforeAndInside", {
            TokenFactory::createWhile(
                TokenFactory::createEqualsExpr(TokenFactory::createVariable("x"), TokenFactory::createInt(1)),
                {
                    TokenFactory::createAssign("x", TokenFactory::createAddExpr(
                        TokenFactory::createVariable("y"),
                        TokenFactory::createInt(3)
                    )),
                    TokenFactory::createCall("hello"),
                    TokenFactory::createRead("t"),
                    TokenFactory::createPrint("u"),
                    TokenFactory::createWhile(
                        TokenFactory::createEqualsExpr(TokenFactory::createVariable("x"), TokenFactory::createInt(1)),
                        {
                            TokenFactory::createAssign("x", TokenFactory::createAddExpr(
                                TokenFactory::createVariable("y"),
                                TokenFactory::createInt(3)
                            )),
                            TokenFactory::createCall("hello"),
                            TokenFactory::createRead("t"),
                            TokenFactory::createPrint("u"),
                        }
                    ),
                }
            ),
        })
    });
}

std::shared_ptr<TokenStream> TokenizedTestProgramProducer::createWhileWithNestedWhilePlusNestedStmtsBeforeAfterAndInside() const {
    return TokenFactory::createProgram({
        TokenFactory::createProcedure("WhileWithNestedWhilePlusNestedStmtsBeforeAfterAndInside", {
            TokenFactory::createWhile(
                TokenFactory::createEqualsExpr(TokenFactory::createVariable("x"), TokenFactory::createInt(1)),
                {
                    TokenFactory::createAssign("x", TokenFactory::createAddExpr(
                        TokenFactory::createVariable("y"),
                        TokenFactory::createInt(3)
                    )),
                    TokenFactory::createCall("hello"),
                    TokenFactory::createRead("t"),
                    TokenFactory::createPrint("u"),
                    TokenFactory::createWhile(
                        TokenFactory::createEqualsExpr(TokenFactory::createVariable("x"), TokenFactory::createInt(1)),
                        {
                            TokenFactory::createAssign("x", TokenFactory::createAddExpr(
                                TokenFactory::createVariable("y"),
                                TokenFactory::createInt(3)
                            )),
                            TokenFactory::createCall("hello"),
                            TokenFactory::createRead("t"),
                            TokenFactory::createPrint("u"),
                        }
                    ),
                    TokenFactory::createAssign("x", TokenFactory::createAddExpr(
                        TokenFactory::createVariable("y"),
                        TokenFactory::createInt(3)
                    )),
                    TokenFactory::createCall("hello"),
                    TokenFactory::createRead("t"),
                    TokenFactory::createPrint("u"),
                }
            ),
        })
    });
}

std::shared_ptr<TokenStream> TokenizedTestProgramProducer::createWhileWithNestedWhilePlusNestedStmtsAfterAndInside() const {
    return TokenFactory::createProgram({
        TokenFactory::createProcedure("WhileWithNestedWhilePlusNestedStmtsAfterAndInside", {
            TokenFactory::createWhile(
                TokenFactory::createEqualsExpr(TokenFactory::createVariable("x"), TokenFactory::createInt(1)),
                {
                    TokenFactory::createWhile(
                        TokenFactory::createEqualsExpr(TokenFactory::createVariable("x"), TokenFactory::createInt(1)),
                        {
                            TokenFactory::createAssign("x", TokenFactory::createAddExpr(
                                TokenFactory::createVariable("y"),
                                TokenFactory::createInt(3)
                            )),
                            TokenFactory::createCall("hello"),
                            TokenFactory::createRead("t"),
                            TokenFactory::createPrint("u"),
                        }
                    ),
                    TokenFactory::createAssign("x", TokenFactory::createAddExpr(
                        TokenFactory::createVariable("y"),
                        TokenFactory::createInt(3)
                    )),
                    TokenFactory::createCall("hello"),
                    TokenFactory::createRead("t"),
                    TokenFactory::createPrint("u"),
                }
            ),
        })
    });
}

std::shared_ptr<TokenStream> TokenizedTestProgramProducer::createSequentialNestingChain() const {
    return TokenFactory::createProgram({
        TokenFactory::createProcedure("AssignCallPrintRead", {
            TokenFactory::createAssign("t", TokenFactory::createAddExpr(
                TokenFactory::createMultiplyExpr(
                    TokenFactory::createGrouping(TokenFactory::createAddExpr(
                        TokenFactory::createInt(1),
                        TokenFactory::createVariable("y")
                    )),
                    TokenFactory::createInt(3)
                ),
                TokenFactory::createVariable("y")
            )),
            TokenFactory::createCall("IfElseWithStmtsBeforeAndInside"),
            TokenFactory::createRead("t"),
            TokenFactory::createPrint("u"),
        }),
        TokenFactory::createProcedure("IfElseWithStmtsBeforeAndInside", {
            TokenFactory::createAssign("x", TokenFactory::createAddExpr(
                TokenFactory::createVariable("y"),
                TokenFactory::createInt(3)
            )),
            TokenFactory::createCall("IfElseWithNestedIfElsePlusNestedStmtsBeforeAndInside"),
            TokenFactory::createRead("t"),
            TokenFactory::createPrint("u"),
            TokenFactory::createIf(
                TokenFactory::createEqualsExpr(TokenFactory::createVariable("x"), TokenFactory::createInt(1)),
                {
                    TokenFactory::createAssign("t", TokenFactory::createAddExpr(
                        TokenFactory::createMultiplyExpr(
                            TokenFactory::createGrouping(TokenFactory::createAddExpr(
                                TokenFactory::createInt(1),
                                TokenFactory::createVariable("y")
                            )),
                            TokenFactory::createInt(3)
                        ),
                        TokenFactory::createVariable("y")
                    )),
                    TokenFactory::createRead("t"),
                    TokenFactory::createPrint("u"),
                },
                {
                    TokenFactory::createAssign("x", TokenFactory::createAddExpr(
                        TokenFactory::createVariable("y"),
                        TokenFactory::createInt(3)
                    )),
                    TokenFactory::createRead("t"),
                    TokenFactory::createPrint("u"),
                }
            ),
        }),
        TokenFactory::createProcedure("IfElseWithNestedIfElsePlusNestedStmtsBeforeAndInside", {
            TokenFactory::createIf(
                TokenFactory::createEqualsExpr(TokenFactory::createVariable("x"), TokenFactory::createInt(1)),
                {
                    TokenFactory::createAssign("x", TokenFactory::createAddExpr(
                        TokenFactory::createVariable("y"),
                        TokenFactory::createInt(3)
                    )),
                    TokenFactory::createRead("t"),
                    TokenFactory::createPrint("u"),
                    TokenFactory::createIf(
                        TokenFactory::createEqualsExpr(TokenFactory::createVariable("x"), TokenFactory::createInt(1)),
                        {
                            TokenFactory::createAssign("t", TokenFactory::createAddExpr(
                                TokenFactory::createMultiplyExpr(
                                    TokenFactory::createGrouping(TokenFactory::createAddExpr(
                                        TokenFactory::createInt(1),
                                        TokenFactory::createVariable("y")
                                    )),
                                    TokenFactory::createInt(3)
                                ),
                                TokenFactory::createVariable("y")
                            )),
                            TokenFactory::createRead("t"),
                            TokenFactory::createPrint("u"),
                        },
                        {
                            TokenFactory::createAssign("x", TokenFactory::createAddExpr(
                                TokenFactory::createVariable("y"),
                                TokenFactory::createInt(3)
                            )),
                            TokenFactory::createRead("t"),
                            TokenFactory::createPrint("u"),
                        }
                    ),
                },
                {
                    TokenFactory::createAssign("x", TokenFactory::createAddExpr(
                        TokenFactory::createVariable("y"),
                        TokenFactory::createInt(3)
                    )),
                    TokenFactory::createRead("t"),
                    TokenFactory::createPrint("u"),
                    TokenFactory::createIf(
                        TokenFactory::createEqualsExpr(TokenFactory::createVariable("x"), TokenFactory::createInt(1)),
                        {
                            TokenFactory::createAssign("x", TokenFactory::createAddExpr(
                                TokenFactory::createVariable("y"),
                                TokenFactory::createInt(3)
                            )),
                            TokenFactory::createRead("t"),
                            TokenFactory::createPrint("u"),
                        },
                        {
                            TokenFactory::createAssign("x", TokenFactory::createAddExpr(
                                TokenFactory::createVariable("y"),
                                TokenFactory::createInt(3)
                            )),
                            TokenFactory::createRead("t"),
                            TokenFactory::createPrint("u"),
                        }
                    ),
                }
            ),
        })
    });
}