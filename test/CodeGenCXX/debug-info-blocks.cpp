// RUN: %clang_cc1 %s -debug-info-kind=line-tables-only -fblocks -S -emit-llvm -o - | FileCheck %s
// RUN: %clang_cc1 %s -debug-info-kind=line-directives-only -fblocks -S -emit-llvm -o - | FileCheck %s

struct A {
  A();
  A(const A &);
  ~A();
};

void test() {
  __block A a;
}

// CHECK: !DISubprogram(name: "__Block_byref_object_copy_",
// CHECK-SAME:          line: 11,
// CHECK-SAME:          isLocal: true, isDefinition: true
// CHECK: !DISubprogram(name: "__Block_byref_object_dispose_",
// CHECK-SAME:          line: 11,
// CHECK-SAME:          isLocal: true, isDefinition: true
