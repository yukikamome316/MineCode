#include <stmtProcessor.h>
#include <parserContext.h>
#include <parserCore.h>

void stmtProcessor::For    (parserCtx::parserContext& ctx){
    while(ctx.iter.hasData()){
        if(ctx.iter.peek()==L"}")break;
        parserCore::stmt(ctx);
    }
}

void stmtProcessor::Forr   (parserCtx::parserContext& ctx){

}

void stmtProcessor::While  (parserCtx::parserContext& ctx){

}

void stmtProcessor::If     (parserCtx::parserContext& ctx){

}

void stmtProcessor::Func   (parserCtx::parserContext& ctx){

}

void stmtProcessor::Put    (parserCtx::parserContext& ctx){

}

void stmtProcessor::Assign (parserCtx::parserContext& ctx){

}
