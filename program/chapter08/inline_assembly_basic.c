extern int global;
extern int global2;

void inline_assembly_sample()
{
  int a, b, c;
  asm volatile("addi %0,%1,%2"
               :"=r"(a)				// rなのでレジスタが指定される。
               :"r"(500), 			// レジスタに即値が代入され渡される
               "i"(100)				// 即値が渡される。
               );
  asm volatile ("lw %0, %1"
                :"=r"(b)
                :"m"(global));		// メモリの場所が渡される。
  asm volatile ("mv	%0, %1"
               	:"=r"(c)
                :"r"(&global2));	// ポインタ（メモリアドレス）が渡される。
}
