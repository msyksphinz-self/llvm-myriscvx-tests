# テストプログラムの実行方法

本リポジトリは「作って学ぶコンピュータアーキテクチャ」のサンプルプログラムを含んでいます。

## 基本的な実行方法

本リポジトリは、LLVMリポジトリと同じディレクトリ階層に配置されていることを想定しています。

```
.
├── llvm-myriscvx120
└── llvm-myriscvx-tests
```

ディレクトリ名としてllvm-myriscvx120以外のディレクトリを使用する場合は、`llvm-myriscvx-tests/program/common.mk`を適宜書き換えてください。

```makefile
CLANG   ?= $(realpath ../../../llvm-myriscvx120/build/bin/clang        ../../../../llvm-myriscvx120/build/bin/clang       )
LLC     ?= $(realpath ../../../llvm-myriscvx120/build/bin/llc              ../../../../llvm-myriscvx120/build/bin/llc             )
DUMP    ?= $(realpath ../../../llvm-myriscvx120/build/bin/llvm-dis         ../../../../llvm-myriscvx120/build/bin/llvm-dis        )
MC      ?= $(realpath ../../../llvm-myriscvx120/build/bin/llvm-mc          ../../../../llvm-myriscvx120/build/bin/llvm-mc         )
OBJDUMP ?= $(realpath ../../../llvm-myriscvx120/build/bin/llvm-objdump ../../../../llvm-myriscvx120/build/bin/llvm-objdump)
```

