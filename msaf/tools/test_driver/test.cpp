//
// Created by canli on 2025/1/15.
//

#include <cstdio>
#include <vector>

#include "framework/ModularAnalysis.h"
#include "Util/CommandLine.h"
#include "Util/Options.h"
#include "SVF-LLVM/SVFIRBuilder.h"
#include "WPA/Andersen.h"
#include "Graphs/VFG.h"

using namespace SVF;

class MyAnalysis : public ModularAnalysis {
    public:
    MyAnalysis(): ModularAnalysis(nullptr) {
    }

    ~MyAnalysis() {}

    void run() {
        printf("Running...\n");
    }

protected:
    void processAddr(const AddrStmt *addrStmt) override {  }

    void processCopy(const CopyStmt *copyStmt) override {  }

    void processStore(const StoreStmt *storeStmt) override {  }

    void processLoad(const LoadStmt *loadStmt) override {  }

    void processGep(const GepStmt *gepStmt) override {  }

    void processPhi(const PhiStmt *phiStmt) override { }

    void processSelect(const SelectStmt *selectStmt) override {  }

    void processCmp(const CmpStmt *cmpStmt) override {  }

    void processBinaryOP(const BinaryOPStmt *binOPStmt) override {  }

    void processUnaryOP(const UnaryOPStmt *unaryOPStmt) override {  }

    void processBranch(const BranchStmt *branchStmt) override {  }

    void processCall(const CallICFGNode *call) override {  }
};

typedef FIFOWorkList<NodeID> WorkList;

void getCallGraphSCCRevTopoOrder(SCCDetection<PTACallGraph*>* callGraphSCC, WorkList& worklist) {
    NodeStack revTopoNodeStack = callGraphSCC->revTopoNodeStack();
    while(!revTopoNodeStack.empty())
    {
        NodeID repNodeId = revTopoNodeStack.top();
        revTopoNodeStack.pop();

        for (auto callGraphNodeId : callGraphSCC->subNodes(repNodeId))
        {
            worklist.push(callGraphNodeId);
        }
    }
}

int main(int argc, char **argv) {
    std::vector<std::string> moduleNameVec;
    moduleNameVec = OptionBase::parseOptions(
            argc, argv, "Whole Program Points-to Analysis", "[options] <input-bitcode...>"
    );

    if (Options::WriteAnder() == "ir_annotator") {
        LLVMModuleSet::preProcessBCs(moduleNameVec);
    }

    SVFModule *svfModule = LLVMModuleSet::buildSVFModule(moduleNameVec);

    /// Build Program Assignment Graph (SVFIR)
    SVFIRBuilder builder(svfModule);
    SVFIR *pag = builder.build();

    /// Create Andersen's pointer analysis
    Andersen *ander = AndersenWaveDiff::createAndersenWaveDiff(pag);

    /// Call Graph
    PTACallGraph *callgraph = ander->getCallGraph();

    /// ICFG
    // ICFG* icfg = pag->getICFG();

    /// Value-Flow Graph (VFG)
    // VFG* vfg = new VFG(callgraph);

    /// Sparse value-flow graph (SVFG)
    /// SVFGBuilder svfBuilder;
    /// SVFG* svfg = svfBuilder.buildFullSVFG(ander);

    SCCDetection<PTACallGraph *> *callGraphSCC = new SCCDetection(callgraph);
    callGraphSCC->find();

    WorkList worklist;
    getCallGraphSCCRevTopoOrder(callGraphSCC, worklist);
    while (!worklist.empty())
    {
        NodeID callGraphNodeID = worklist.pop();
        PTACallGraphNode *subCallGraphNode = callgraph->getCallGraphNode(callGraphNodeID);
        const SVFFunction *fun = subCallGraphNode->getFunction();
        std::cout << fun->getName() << std::endl;
    }
}