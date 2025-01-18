//
// Created by Liture on 2025/1/5.
//

#ifndef MSAF_MODULARANALYSIS_H
#define MSAF_MODULARANALYSIS_H

#include "SVFIR/SVFIR.h"

using namespace SVF;

class ModularAnalysis {

public:
    ModularAnalysis(const SVFFunction *curFun) { }

    ~ModularAnalysis() {  }

    void run();

    const SVFFunction *getCurFun(const SVFFunction *curFun);
protected:

    ///> process a single basic block
    virtual void beforeProcessBasicBlock(const SVFBasicBlock *bb);
    virtual void processBasicBlock(const SVFBasicBlock *bb);
    virtual void afterProcessBasicBlock(const SVFBasicBlock *bb);

    ///> schedule stmt process
    virtual void beforeProcessStmt(const SVFStmt *stmt);
    virtual void processStmt(const SVFStmt *stmt);
    virtual void afterProcessStmt(const SVFStmt *stmt);

    ///> process all other kinds of statements
    virtual void processAddr(const AddrStmt *addrStmt) = 0;
    virtual void processCopy(const CopyStmt *copyStmt) = 0;
    virtual void processStore(const StoreStmt *storeStmt) = 0;
    virtual void processLoad(const LoadStmt *loadStmt) = 0;
    virtual void processGep(const GepStmt *gepStmt) = 0;
    virtual void processPhi(const PhiStmt *phiStmt) = 0;
    virtual void processSelect(const SelectStmt *selectStmt) = 0;
    virtual void processCmp(const CmpStmt *cmpStmt) = 0;
    virtual void processBinaryOP(const BinaryOPStmt *binOPStmt) = 0;
    virtual void processUnaryOP(const UnaryOPStmt *unaryOPStmt) = 0;
    virtual void processBranch(const BranchStmt *branchStmt) = 0;

    ///> process call
    virtual void processCall(const CallICFGNode *call) = 0;
private:
    ///> current function analyzed
    const SVFFunction *curFun;
};


#endif //MSAF_MODULARANALYSIS_H
