# MSAF: A Modular Static Analysis Framework

## 1. Design
Here is a static analysis framework for bug finding.Its features:
- Modular.
  - It's a modular static analysis framework, means it's not a whole program analysis framework. It follows a bottom-up and summary-based modular analysis paradigm.
- Extensible
  - All checker builds on the extensible framework.
  - It supports several checkers, such as Use of Uninitialized Variable (UUV or UBI), buffer overflow.
- Unsound
  - It means that it is not for rigorous verification and aims to find more real bugs in low false positive.

## 2. Build
This project depends on [SVF framework](https://github.com/SVF-tools/SVF), so you must first build SVF.

### 2.1 build SVF
Now we use `LLVM 16.0.6` and `z3-4.8.8` to build SVF

Follows the [SVF Wiki](https://github.com/svf-tools/SVF/wiki/Setup-Guide#getting-started) to build SVF.

### 2.2 build MSAF

```shell
mkdir cmake-build-release
cd cmake-build-release
cmake -DLLVM_DIR=${LLVM_DIR} -DSVF_DIR=${SVF_DIR} .. 
```

for example:
```shell
mkdir cmake-build-release
cd cmake-build-release
cmake -DLLVM_DIR=/Users/liture/CLionProjects/SVF-Dev-Env/llvm-project-llvmorg-16.0.6/llvm/cmake-build-relwithdebinfo -DSVF_DIR=/Users/liture/CLionProjects/SVF-Dev-Env/SVF .. 
```
