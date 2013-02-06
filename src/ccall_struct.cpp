//for clang to llvm use CodeGenTypes::ConvertType()
//for llvm to clang, manual?
//  via BuiltinType(Kind) WRONG
//  Kind declared in clang/AST/BuiltinTypes.def
//  unsigned: unsigned char, unsigned short, unsigned int, unsigned long long, unsigned long, unsigned __uint128_t
//  signed: same
//  floats: float, double, long double
//  void
//  
//  All created / accessed through ASTContext

ASTContext::ASTContext  (   LangOptions &   LOpts,
SourceManager &     SM, 
const TargetInfo *  t,  
IdentifierTable &   idents,
SelectorTable &     sels,
Builtin::Context &  builtins,
unsigned    size_reserve,
bool    DelayInitialization = false 
)   
//  (Context, SelectorTable, IdentifierTable, LangOptions are easy)
//  (TargetInfo is a big pain)
//  (SourceManager looks easy enough)
//
//  in CGCall.h
//    static CGFunctionInfo *create(unsigned llvmCC,
//                                  const FunctionType::ExtInfo &extInfo,
//                                  CanQualType resultType,
//                                  ArrayRef<CanQualType> argTypes,
//                                  RequiredArgs required);
//  in ABIInfo.h
//    virtual void computeInfo(CodeGen::CGFunctionInfo &FI) const = 0;
// 
//  called from
const CGFunctionInfo &
CodeGenTypes::arrangeLLVMFunctionInfo(CanQualType resultType,
                                      ArrayRef<CanQualType> argTypes,
                                      FunctionType::ExtInfo info,
                                      RequiredArgs required) {
// final stage
llvm::FunctionType *
CodeGenTypes::GetFunctionType(const CGFunctionInfo &FI) {
//  then
RValue CodeGenFunction::EmitCall(const CGFunctionInfo &CallInfo,
                                 llvm::Value *Callee,
                                 ReturnValueSlot ReturnValue,
                                 const CallArgList &CallArgs,
                                 const Decl *TargetDecl,
                                 llvm::Instruction **callOrInvoke) {
// (RValue and ReturnValueSlot, CallArgList are easy to work with)  
// (TargetDecl can just be null -- it is info from Callee target to copy to call)
// Fn will need attribute NoUnwind (or it gets turned into an invoke)
