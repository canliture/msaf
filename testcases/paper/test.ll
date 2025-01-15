; ModuleID = 'test.ll'
source_filename = "test.c"
target datalayout = "e-m:w-p270:32:32-p271:32:32-p272:64:64-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-pc-windows-msvc19.42.34435"

; Function Attrs: noinline nounwind uwtable
define dso_local ptr @mem_alloc(i32 noundef %sz) #0 {
entry:
  %conv = zext i32 %sz to i64
  %mul = mul i64 4, %conv
  %call = call noalias ptr @malloc(i64 noundef %mul) #2
  ret ptr %call
}

; Function Attrs: allocsize(0)
declare dso_local noalias ptr @malloc(i64 noundef) #1

; Function Attrs: noinline nounwind uwtable
define dso_local void @set_mem(ptr noundef %ar, i32 noundef %x) #0 {
entry:
  %arrayidx = getelementptr inbounds i32, ptr %ar, i64 0
  store i32 %x, ptr %arrayidx, align 4
  %idxprom = sext i32 %x to i64
  %arrayidx1 = getelementptr inbounds i32, ptr %ar, i64 %idxprom
  store i32 0, ptr %arrayidx1, align 4
  ret void
}

; Function Attrs: noinline nounwind uwtable
define dso_local void @baz(i32 noundef %arg) #0 {
entry:
  %call = call ptr @mem_alloc(i32 noundef 100)
  call void @set_mem(ptr noundef %call, i32 noundef 1)
  %arrayidx = getelementptr inbounds i32, ptr %call, i64 0
  %0 = load i32, ptr %arrayidx, align 4
  %arrayidx1 = getelementptr inbounds i32, ptr %call, i64 1
  %1 = load i32, ptr %arrayidx1, align 4
  %sub = sub nsw i32 %0, 1
  %idxprom = sext i32 %sub to i64
  %arrayidx2 = getelementptr inbounds i32, ptr %call, i64 %idxprom
  store i32 0, ptr %arrayidx2, align 4
  %sub3 = sub nsw i32 %1, 1
  %idxprom4 = sext i32 %sub3 to i64
  %arrayidx5 = getelementptr inbounds i32, ptr %call, i64 %idxprom4
  store i32 0, ptr %arrayidx5, align 4
  ret void
}

attributes #0 = { noinline nounwind uwtable "min-legal-vector-width"="0" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "tune-cpu"="generic" }
attributes #1 = { allocsize(0) "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "tune-cpu"="generic" }
attributes #2 = { allocsize(0) }

!llvm.module.flags = !{!0, !1, !2}
!llvm.ident = !{!3}

!0 = !{i32 1, !"wchar_size", i32 2}
!1 = !{i32 8, !"PIC Level", i32 2}
!2 = !{i32 7, !"uwtable", i32 2}
!3 = !{!"clang version 16.0.6 (https://github.com/llvm/llvm-project.git 7cbf1a2591520c2491aa35339f227775f4d3adf6)"}
