#pragma once
#ifndef PARSER_CONTEXT_H
#define PARSER_CONTEXT_H

#include <unordered_map>
#include <sstream>
#include "typedIterator.hxx"

namespace parserCtx
{
    enum varType{
        FLOAT,
        INT
    };
    using streamType = std::wstringstream;
    using iterType   = iterator<std::wstring>;
    using varsType   = std::unordered_map<std::string,varType>;
    struct parserContext{
        parserContext();
        streamType stream;
        iterType iter;
        varsType variables;
    };

} // namespace parserCtx


#endif