#include "CompilerParser.h"
#include <iostream>
using namespace std;
/**
 * Constructor for the CompilerParser
 * @param tokens A linked list of tokens to be parsed
 */

// static int currenttoken = 0;

CompilerParser::CompilerParser(std::vector<Token *> tokens)
{
    currenttoken = 0;
    checknumber = tokens.size();
    for (unsigned int i = 0; i < tokens.size(); i++)
    {
        PT.push_back(tokens[i]);
    }
}

/**
 * Generates a parse tree for a single program
 */
ParseTree *CompilerParser::compileProgram()
{
    for (int i = 0; i < checknumber; i++)
    {
        if (PT.at(i)->getType() == "")
        {
            throw ParseException();
        }
    }
    if (PT.at(currenttoken)->getValue() == "class" && PT.at(currenttoken)->getType() == "keyword")
    {
        return compileClass();
    }
    else
    {
        throw ParseException();
    }
}

/**
 * Generates a parse tree for a single class
 */
// ParseTree* CompilerParser::compileClass() {
// //     if(PT.empty()==0){
// //         // cout<<PT.size()<<endl;
// //         // cout<<PT.at(3)->getValue()<<endl;
// //         ParseTree* CLASS = new ParseTree("class","");
// //         while(PT.at(currenttoken)->getValue()!="{"){
// //             CLASS->addChild(PT.at(currenttoken));
// //             currenttoken++;
// //         }
// //         CLASS->addChild(PT.at(currenttoken));
// //         currenttoken++;
// //         while(currenttoken!=PT.size()){
// //             if((PT.at(currenttoken)->getValue()=="static"&&PT.at(currenttoken)->getType()=="keyword")||
// //             (PT.at(currenttoken)->getValue()=="field"&&PT.at(currenttoken)->getType()=="keyword")){
// //                 CLASS->addChild(compileClassVarDec());
// //             }
// //             else if((PT.at(currenttoken)->getValue()=="function"&&PT.at(currenttoken)->getType()=="keyword")||
// //             (PT.at(currenttoken)->getValue()=="constructor"&&PT.at(currenttoken)->getType()=="keyword")||
// //             (PT.at(currenttoken)->getValue()=="method"&&PT.at(currenttoken)->getType()=="keyword")){
// //                 CLASS->addChild(compileSubroutine());
// //             }
// //             else if(PT.at(currenttoken)->getValue()=="}"&&PT.at(currenttoken)->getType()=="symbol"){
// //                 CLASS->addChild(PT.at(currenttoken));
// //                 currenttoken++;
// //             }
// //             else{
// //                 throw ParseException();
// //             }
// //             if(currenttoken>=PT.size()){
// //                 break;
// //             }
// //         }
// //         return CLASS;
// //     }
// //     return NULL;
// // }
// for(int i  = 0;i<checknumber;i++){
//         if(PT.at(i)->getType() == ""){
//             throw ParseException();
//         }
//     }
//     if(PT.at(currenttoken)->getValue()=="class"&&PT.at(currenttoken)->getType()=="keyword"){
//         return compileClass();
//     }else{
//         throw ParseException();
//     }
// }

/**
 * Generates a parse tree for a single class
 */
ParseTree *CompilerParser::compileClass()
{
    if (PT.empty() == 0)
    {
        // cout<<PT.size()<<endl;
        // cout<<PT.at(3)->getValue()<<endl;
        ParseTree *CLASS = new ParseTree("class", "");
        if (PT.at(currenttoken)->getType() == "keyword" && PT.at(currenttoken)->getValue() == "class")
        {
            CLASS->addChild(PT.at(currenttoken));
            currenttoken++;
        }
        else
        {
            throw ParseException();
        }
        if (PT.at(currenttoken)->getType() == "identifier")
        {
            CLASS->addChild(PT.at(currenttoken));
            currenttoken++;
        }
        else
        {
            throw ParseException();
        }
        if (PT.at(currenttoken)->getType() == "symbol" && PT.at(currenttoken)->getValue() == "{")
        {
            CLASS->addChild(PT.at(currenttoken));
            currenttoken++;
        }
        else
        {
            throw ParseException();
        }
        while ((PT.at(currenttoken)->getType() == "keyword" && PT.at(currenttoken)->getValue() == "static") ||
               (PT.at(currenttoken)->getType() == "keyword" && PT.at(currenttoken)->getValue() == "field"))
        {
            CLASS->addChild(compileClassVarDec());
        }
        while ((PT.at(currenttoken)->getType() == "keyword" && PT.at(currenttoken)->getValue() == "constructor") ||
               (PT.at(currenttoken)->getType() == "keyword" && PT.at(currenttoken)->getValue() == "function") ||
               (PT.at(currenttoken)->getType() == "keyword" && PT.at(currenttoken)->getValue() == "method"))
        {
            CLASS->addChild(compileSubroutine());
        }
        if (PT.at(currenttoken)->getType() == "symbol" && PT.at(currenttoken)->getValue() == "}")
        {
            CLASS->addChild(PT.at(currenttoken));
            currenttoken++;
        }
        else
        {
            throw ParseException();
        }
        return CLASS;
    }
    return NULL;
}

/**
 * Generates a parse tree for a static variable declaration or field declaration
 */
ParseTree *CompilerParser::compileClassVarDec()
{
    //     if(PT.empty()==0){
    //         ParseTree* CVD = new ParseTree("classVarDec","");
    //         while(PT.at(currenttoken)->getValue()!=";"){
    //             CVD->addChild(PT.at(currenttoken));
    //             currenttoken++;
    //             if(currenttoken>=PT.size()){
    //                 break;
    //             }
    //         }
    //         ParseTree* seg = new ParseTree("symbol",";");
    //         CVD->addChild(seg);
    //         currenttoken++;
    //         return CVD;
    //     }
    //     return NULL;
    // }
    if (PT.empty() == 0){
        ParseTree *CVD = new ParseTree("classVarDec", "");
        if ((PT.at(currenttoken)->getType() == "keyword" && PT.at(currenttoken)->getValue() == "static") || 
            (PT.at(currenttoken)->getType() == "keyword" && PT.at(currenttoken)->getValue() == "field")){
            CVD->addChild(PT.at(currenttoken));
            currenttoken++;
        }else{
            throw ParseException();
        }
        if ((PT.at(currenttoken)->getType() == "keyword" && PT.at(currenttoken)->getValue() == "int") || 
            (PT.at(currenttoken)->getType() == "keyword" && PT.at(currenttoken)->getValue() == "char") || 
            (PT.at(currenttoken)->getType() == "keyword" && PT.at(currenttoken)->getValue() == "boolean") || 
             PT.at(currenttoken)->getType() == "identifier"){
                CVD->addChild(PT.at(currenttoken));
                currenttoken++;
        }else{
            throw ParseException();
        }
        if (PT.at(currenttoken)->getType() == "identifier"){
            CVD->addChild(PT.at(currenttoken));
            currenttoken++;
        }else{
            throw ParseException();
        }
        while ((PT.at(currenttoken)->getType() == "symbol" && PT.at(currenttoken)->getValue() == ",") || 
                PT.at(currenttoken)->getType() == "identifier"){
            CVD->addChild(PT.at(currenttoken));
            currenttoken++;
        }
        if (PT.at(currenttoken)->getType() == "symbol" && PT.at(currenttoken)->getValue() == ";"){
            CVD->addChild(PT.at(currenttoken));
            currenttoken++;
        }else{
            throw ParseException();
        }
        return CVD;
    }
    return NULL;
}

/**
 * Generates a parse tree for a method, function, or constructor
 */
ParseTree *CompilerParser::compileSubroutine()
{
    if (PT.empty() == 0)
    {
        ParseTree *SBT = new ParseTree("subroutineDec", "");
        while (PT.at(currenttoken)->getValue() != "(")
        {
            SBT->addChild(PT.at(currenttoken));
            currenttoken++;
            if (currenttoken >= PT.size())
            {
                break;
            }
        }
        ParseTree *cbracket = new ParseTree("symbol", "(");
        SBT->addChild(cbracket);
        currenttoken++;
        SBT->addChild(compileParameterList());
        ParseTree *cbracket2 = new ParseTree("symbol", ")");
        SBT->addChild(cbracket2);
        currenttoken++;
        SBT->addChild(compileSubroutineBody());
        return SBT;
    }
    return NULL;
}

/**
 * Generates a parse tree for a subroutine's parameters
 */
ParseTree *CompilerParser::compileParameterList()
{
    if (PT.empty() == 0)
    {
        ParseTree *PL = new ParseTree("parameterList", "");
        while (PT.at(currenttoken)->getValue() != ")")
        {
            PL->addChild(PT.at(currenttoken));
            currenttoken++;
            if (currenttoken >= PT.size())
            {
                break;
            }
        }
        return PL;
    }
    return NULL;
}

/**
 * Generates a parse tree for a subroutine's body
 */
ParseTree *CompilerParser::compileSubroutineBody()
{
    if (PT.empty() == 0)
    {
        ParseTree *SBTBD = new ParseTree("subroutineBody", "");
        if (PT.at(currenttoken)->getType() == "symbol" && PT.at(currenttoken)->getValue() == "{")
        {
            SBTBD->addChild(PT.at(currenttoken));
            currenttoken++;
        }
        else
        {
            throw ParseException();
        }
        if (PT.at(currenttoken)->getValue() == "}")
        {
            SBTBD->addChild(compileStatements());
        }
        while (PT.at(currenttoken)->getValue() != "}")
        {
            if (PT.at(currenttoken)->getValue() == "var")
            {
                SBTBD->addChild(compileVarDec());
            }
            else
            {
                if ((PT.at(currenttoken)->getType() == "keyword" && PT.at(currenttoken)->getValue() == "let") ||
                    (PT.at(currenttoken)->getType() == "keyword" && PT.at(currenttoken)->getValue() == "if") ||
                    (PT.at(currenttoken)->getType() == "keyword" && PT.at(currenttoken)->getValue() == "while") ||
                    (PT.at(currenttoken)->getType() == "keyword" && PT.at(currenttoken)->getValue() == "do") ||
                    (PT.at(currenttoken)->getType() == "keyword" && PT.at(currenttoken)->getValue() == "return"))
                {
                    SBTBD->addChild(compileStatements());
                }
                else
                {
                    throw ParseException();
                }
            }
            if (currenttoken >= PT.size())
            {
                break;
            }
        }
        ParseTree *sbracket2 = new ParseTree("symbol", "}");
        SBTBD->addChild(sbracket2);
        currenttoken++;
        return SBTBD;
    }
    return NULL;
}

/**
 * Generates a parse tree for a variable declaration
 */
ParseTree *CompilerParser::compileVarDec()
{
    if (PT.empty() == 0)
    {
        ParseTree *VD = new ParseTree("varDec", "");
        while (PT.at(currenttoken)->getValue() != ";")
        {
            VD->addChild(PT.at(currenttoken));
            currenttoken++;
            if (currenttoken >= PT.size())
            {
                break;
            }
        }
        ParseTree *seg = new ParseTree("symbol", ";");
        VD->addChild(seg);
        currenttoken++;
        return VD;
    }
    return NULL;
}
/**
 * Generates a parse tree for a series of statements
 */
ParseTree *CompilerParser::compileStatements()
{
    if (PT.empty() == 0)
    {
        ParseTree *STMS = new ParseTree("statements", "");
        // if(PT.at(currenttoken)->getValue()!="let"&&
        // PT.at(currenttoken)->getValue()!="if"&&
        // PT.at(currenttoken)->getValue()!="while"&&
        // PT.at(currenttoken)->getValue()!="do"&&
        // PT.at(currenttoken)->getValue()!="return"){
        //     throw ParseException();
        // }
        while ((PT.at(currenttoken)->getType() == "keyword" && PT.at(currenttoken)->getValue() == "let") ||
               (PT.at(currenttoken)->getType() == "keyword" && PT.at(currenttoken)->getValue() == "if") ||
               (PT.at(currenttoken)->getType() == "keyword" && PT.at(currenttoken)->getValue() == "while") ||
               (PT.at(currenttoken)->getType() == "keyword" && PT.at(currenttoken)->getValue() == "do") ||
               (PT.at(currenttoken)->getType() == "keyword" && PT.at(currenttoken)->getValue() == "return"))
        {
            if (PT.at(currenttoken)->getValue() == "let")
            {
                STMS->addChild(compileLet());
            }
            else if (PT.at(currenttoken)->getValue() == "if")
            {
                STMS->addChild(compileIf());
            }
            else if (PT.at(currenttoken)->getValue() == "while")
            {
                STMS->addChild(compileWhile());
            }
            else if (PT.at(currenttoken)->getValue() == "do")
            {
                STMS->addChild(compileDo());
            }
            else if (PT.at(currenttoken)->getValue() == "return")
            {
                STMS->addChild(compileReturn());
            }
            if (currenttoken >= PT.size())
            {
                break;
            }
        }
        return STMS;
        // }else{
        //     throw ParseException();
        // }
    }
    return NULL;
}

/**
 * Generates a parse tree for a let statement
 */
ParseTree *CompilerParser::compileLet()
{
    if (PT.empty() == 0)
    {
        ParseTree *LET = new ParseTree("letStatement", "");
        while (PT.at(currenttoken)->getValue() != ";")
        {
            if (PT.at(currenttoken)->getValue() == "[")
            {
                LET->addChild(PT.at(currenttoken));
                currenttoken++;
                LET->addChild(compileExpression());
                LET->addChild(PT.at(currenttoken));
                currenttoken++;
            }
            else
            {
                LET->addChild(PT.at(currenttoken));
                currenttoken++;
            }
            if (currenttoken >= PT.size())
            {
                break;
            }
        }
        ParseTree *SEG = new ParseTree("symbol", ";");
        LET->addChild(SEG);
        currenttoken++;
        return LET;
    }
    return NULL;
}

/**
 * Generates a parse tree for an if statement
 */
ParseTree *CompilerParser::compileIf()
{
    if (PT.empty() == 0)
    {
        ParseTree *IF = new ParseTree("ifStatement", "");
        while (PT.at(currenttoken)->getValue() != "}")
        {
            if (PT.at(currenttoken)->getValue() == "(")
            {
                IF->addChild(PT.at(currenttoken));
                currenttoken++;
                IF->addChild(compileExpression());
                IF->addChild(PT.at(currenttoken));
                currenttoken++;
            }
            if (PT.at(currenttoken)->getValue() == "{")
            {
                IF->addChild(PT.at(currenttoken));
                currenttoken++;
                IF->addChild(compileStatements());
            }
            else
            {
                IF->addChild(PT.at(currenttoken));
                currenttoken++;
            }
            if (currenttoken >= PT.size())
            {
                break;
            }
        }
        IF->addChild(PT.at(currenttoken));
        currenttoken++; //}

        if (PT.at(currenttoken)->getValue() == "else")
        {
            while (PT.at(currenttoken)->getValue() != "}")
            {
                if (PT.at(currenttoken)->getValue() == "(")
                {
                    IF->addChild(PT.at(currenttoken));
                    currenttoken++;
                    IF->addChild(compileExpression());
                    IF->addChild(PT.at(currenttoken));
                    currenttoken++;
                }
                if (PT.at(currenttoken)->getValue() == "{")
                {
                    IF->addChild(PT.at(currenttoken));
                    currenttoken++;
                    IF->addChild(compileStatements());
                }
                else
                {
                    IF->addChild(PT.at(currenttoken));
                    currenttoken++;
                }
                if (currenttoken >= PT.size())
                {
                    break;
                }
            }
            IF->addChild(PT.at(currenttoken));
            currenttoken++; //}
        }
        return IF;
    }
    return NULL;
}

// ParseTree* CompilerParser::compileElse() {
//     if(PT.empty()==0){
//         ParseTree* ELSE = new ParseTree("elseStatement","");
//         while(PT.at(currenttoken)->getValue()!="}"){
//             if (PT.at(currenttoken)->getValue()=="(")
//             {
//                 ELSE->addChild(PT.at(currenttoken));
//                 currenttoken++;
//                 ELSE->addChild(compileExpression());
//                 ELSE->addChild(PT.at(currenttoken));
//                 currenttoken++;
//             }if (PT.at(currenttoken)->getValue()=="{")
//             {
//                 ELSE->addChild(PT.at(currenttoken));
//                 currenttoken++;
//                 ELSE->addChild(compileStatements());
//             }
//             else{
//                 ELSE->addChild(PT.at(currenttoken));
//                 currenttoken++;
//             }
//         }
//         ELSE->addChild(PT.at(currenttoken));
//         currenttoken++;//}
//         return ELSE;
//     }
//     return NULL;
// }
/**
 * Generates a parse tree for a while statement
 */
ParseTree *CompilerParser::compileWhile()
{
    if (PT.empty() == 0)
    {
        ParseTree *WHILE = new ParseTree("whileStatement", "");
        while (PT.at(currenttoken)->getValue() != "}")
        {
            if (PT.at(currenttoken)->getValue() == "(")
            {
                WHILE->addChild(PT.at(currenttoken));
                currenttoken++;
                WHILE->addChild(compileExpression());
                WHILE->addChild(PT.at(currenttoken));
                currenttoken++;
            }
            if (PT.at(currenttoken)->getValue() == "{")
            {
                WHILE->addChild(PT.at(currenttoken));
                currenttoken++;
                WHILE->addChild(compileStatements());
            }
            else
            {
                WHILE->addChild(PT.at(currenttoken));
                currenttoken++;
            }
            if (currenttoken >= PT.size())
            {
                break;
            }
        }
        WHILE->addChild(PT.at(currenttoken));
        currenttoken++; //}
        return WHILE;
    }
    return NULL;
}

/**
 * Generates a parse tree for a do statement
 */
ParseTree *CompilerParser::compileDo()
{
    if (PT.empty() == 0)
    {
        ParseTree *DS = new ParseTree("doStatement", "");
        while (PT.at(currenttoken)->getValue() != ";")
        {
            // if (PT.at(currenttoken)->getValue()=="(")
            // {
            //     DS->addChild(PT.at(currenttoken));
            //     currenttoken++;
            //     DS->addChild(compileExpressionList());
            //     DS->addChild(PT.at(currenttoken));
            //     currenttoken++;
            // }else{
            DS->addChild(PT.at(currenttoken));
            currenttoken++;
            DS->addChild(compileExpression());
            // }
            if (currenttoken >= PT.size())
            {
                break;
            }
        }
        DS->addChild(PT.at(currenttoken));
        currenttoken++; //;
        return DS;
    }
    return NULL;
}

/**
 * Generates a parse tree for a return statement
 */
ParseTree *CompilerParser::compileReturn()
{
    if (PT.empty() == 0)
    {
        ParseTree *RT = new ParseTree("returnStatement", "");
        RT->addChild(PT.at(currenttoken));
        currenttoken++;
        if (PT.at(currenttoken)->getValue() == ";")
        {
            RT->addChild(PT.at(currenttoken));
            currenttoken++;
        }
        else
        {
            RT->addChild(compileExpression());
            ParseTree *seg = new ParseTree("symbol", ";");
            RT->addChild(seg);
            currenttoken++;
        }
        return RT;
    }
    return NULL;
}

/**
 * Generates a parse tree for an expression
 */
ParseTree *CompilerParser::compileExpression()
{
    if (PT.empty() == 0)
    {
        ParseTree *EXP = new ParseTree("expression", "");
        if (PT.at(currenttoken)->getValue() == "skip")
        {
            EXP->addChild(PT.at(currenttoken));
            currenttoken++;
            return EXP;
        }
        while (PT.at(currenttoken)->getValue() != ")" && PT.at(currenttoken)->getValue() != "]")
        {
            EXP->addChild(compileTerm());
            if (PT.at(currenttoken)->getValue() == "+" ||
                PT.at(currenttoken)->getValue() == "-" ||
                PT.at(currenttoken)->getValue() == "*" ||
                PT.at(currenttoken)->getValue() == "/" ||
                PT.at(currenttoken)->getValue() == "&" ||
                PT.at(currenttoken)->getValue() == "|" ||
                PT.at(currenttoken)->getValue() == "<" ||
                PT.at(currenttoken)->getValue() == ">" ||
                PT.at(currenttoken)->getValue() == "=")
            {
                EXP->addChild(PT.at(currenttoken));
                currenttoken++;
                EXP->addChild(compileTerm());
            }
            if (currenttoken >= PT.size())
            {
                break;
            }
        }

        return EXP;
    }
    return NULL;
}

/**
 * Generates a parse tree for an expression term
 */
ParseTree *CompilerParser::compileTerm()
{
    if (PT.empty() == 0)
    {
        ParseTree *TERM = new ParseTree("term", "");
        while (PT.at(currenttoken)->getValue() != ")" && PT.at(currenttoken)->getValue() != "]" &&
               (PT.at(currenttoken)->getValue() != "+" &&
                PT.at(currenttoken)->getValue() != "-" &&
                PT.at(currenttoken)->getValue() != "*" &&
                PT.at(currenttoken)->getValue() != "/" &&
                PT.at(currenttoken)->getValue() != "&" &&
                PT.at(currenttoken)->getValue() != "|" &&
                PT.at(currenttoken)->getValue() != "<" &&
                PT.at(currenttoken)->getValue() != ">" &&
                PT.at(currenttoken)->getValue() != "="))
        {
            if (PT.at(currenttoken)->getValue() == "(")
            {
                TERM->addChild(PT.at(currenttoken));
                currenttoken++;
                TERM->addChild(compileExpression());
                TERM->addChild(PT.at(currenttoken));
                currenttoken++;
            }
            else
            {
                TERM->addChild(PT.at(currenttoken));
                currenttoken++;
            }
            if (currenttoken >= PT.size())
            {
                break;
            }
        }
        return TERM;
    }
    return NULL;
}

/**
 * Generates a parse tree for an expression list
 */
ParseTree *CompilerParser::compileExpressionList()
{
    if (PT.empty() == 0)
    {
        ParseTree *EXPL = new ParseTree("expressionList", "");
        while (PT.at(currenttoken)->getValue() != ")")
        {
            EXPL->addChild(compileExpression());
            if (PT.at(currenttoken)->getValue() == ",")
            {
                EXPL->addChild(PT.at(currenttoken));
                currenttoken++;
                EXPL->addChild(compileExpression());
            }
            if (currenttoken >= PT.size())
            {
                break;
            }
        }
        return EXPL;
    }
    return NULL;
}

const char *ParseException::what()
{
    return "An Exception occurred while parsing!";
}
