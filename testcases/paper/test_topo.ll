; ModuleID = 'test_topo.ll'
source_filename = "test_topo.c"
target datalayout = "e-m:o-p270:32:32-p271:32:32-p272:64:64-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-apple-macosx14.0.0"

; Function Attrs: noinline nounwind ssp uwtable
define void @h() #0 {
entry:
  ret void
}

; Function Attrs: noinline nounwind ssp uwtable
define void @d() #0 {
entry:
  call void @a()
  ret void
}

; Function Attrs: noinline nounwind ssp uwtable
define void @e() #0 {
entry:
  call void @d()
  ret void
}

; Function Attrs: noinline nounwind ssp uwtable
define void @g() #0 {
entry:
  call void @h()
  ret void
}

; Function Attrs: noinline nounwind ssp uwtable
define void @f() #0 {
entry:
  call void @g()
  call void @e()
  ret void
}

; Function Attrs: noinline nounwind ssp uwtable
define void @c() #0 {
entry:
  call void @f()
  ret void
}

; Function Attrs: noinline nounwind ssp uwtable
define void @b() #0 {
entry:
  call void @c()
  ret void
}

; Function Attrs: noinline nounwind ssp uwtable
define void @a() #0 {
entry:
  call void @b()
  ret void
}

; Function Attrs: noinline nounwind ssp uwtable
define void @main0() #0 {
entry:
  call void @a()
  ret void
}

; Function Attrs: noinline nounwind ssp uwtable
define i32 @main() #0 {
entry:
  call void @main0()
  ret i32 0
}

attributes #0 = { noinline nounwind ssp uwtable "frame-pointer"="all" "min-legal-vector-width"="0" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="penryn" "target-features"="+cx16,+cx8,+fxsr,+mmx,+sahf,+sse,+sse2,+sse3,+sse4.1,+ssse3,+x87" "tune-cpu"="generic" }

!llvm.module.flags = !{!0, !1, !2, !3, !4}
!llvm.ident = !{!5}

!0 = !{i32 2, !"SDK Version", [2 x i32] [i32 14, i32 4]}
!1 = !{i32 1, !"wchar_size", i32 4}
!2 = !{i32 8, !"PIC Level", i32 2}
!3 = !{i32 7, !"uwtable", i32 2}
!4 = !{i32 7, !"frame-pointer", i32 2}
!5 = !{!"clang version 16.0.6"}
