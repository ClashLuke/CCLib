__asm__(
"_key_expansion_128:\n"
"	pshufd $0b11111111, %xmm1, %xmm1\n"
"	shufps $0b00010000, %xmm0, %xmm4\n"
"	pxor %xmm4, %xmm0\n"
"	shufps $0b10001100, %xmm0, %xmm4\n"
"	pxor %xmm4, %xmm0\n"
"	pxor %xmm1, %xmm0\n"
"	movaps %xmm0, (%rcx)\n"
"	add $0x10, %rcx\n"
"	ret\n"
"\n"
".globl aesni_set_key;\n"
"aesni_set_key:\n"
"	movups (%rsi), %xmm0		# user key (first 16 bytes)\n"
"	movaps %xmm0, (%rdi)\n"
"	lea 0x10(%rdi), %rcx		# key addr\n"
"	movl %edx, 480(%rdi)\n"
"	pxor %xmm4, %xmm4		# xmm4 is assumed 0 in _key_expansion_x\n"
"	aeskeygenassist $0x1, %xmm0, %xmm1	# round 1\n"
"	call _key_expansion_128\n"
".Ldec_key:\n"
"	sub $0x10, %rcx\n"
"	movaps (%rdi), %xmm0\n"
"	movaps (%rcx), %xmm1\n"
"	movaps %xmm0, 240(%rcx)\n"
"	movaps %xmm1, 240(%rdi)\n"
"	add $0x10, %rdi\n"
"	lea 240-16(%rcx), %rsi\n"
".Ldec_key_loop:\n"
"	movaps (%rdi), %xmm0\n"
"	aesimc %xmm0, %xmm1\n"
"	movaps %xmm1, (%rsi)\n"
"	add $0x10, %rdi\n"
"	sub $0x10, %rsi\n"
"	cmp %rcx, %rdi\n"
"	jb .Ldec_key_loop\n"
"	ret\n"
".globl aesni_enc;\n"
"aesni_enc:\n"
"	movl 480(%rdi), %r9d		# key %rcxgth\n"
"	movups (%rdx), %xmm0		# %rdxut\n"
"	call _aesni_enc1\n"
"	movups %xmm0, (%rsi)		# %rsiut\n"
"	ret\n"
"_aesni_enc1:\n"
"	movaps (%rdi), %xmm2		# key\n"
"	mov %rdi, %r10\n"
"	pxor %xmm2, %xmm0			# round 0\n"
"	add $0x30, %r10\n"
"	lea 0x20(%r10), %r10\n"
"	add $0x20, %r10\n"
"	movaps -0x60(%r10), %xmm2\n"
"	aesenc %xmm2, %xmm0\n"
"	ret\n"
".globl aesni_cbc_enc;\n"
"aesni_cbc_enc:\n"
"	mov 480(%rdi), %r9d\n"
"	movups (%r8), %xmm0	# load iv as initial state\n"
"	movups (%rdx), %xmm1	# load %rdxut\n"
"	pxor %xmm1, %xmm0\n"
"	call _aesni_enc1\n"
"	movups %xmm0, (%rsi)	# store %rsiut\n"
"	add $16, %rdx\n"
"	add $16, %rsi\n"
"	movups (%rdx), %xmm1	# load %rdxut\n"
"	pxor %xmm1, %xmm0\n"
"	call _aesni_enc1\n"
"	movups %xmm0, (%rsi)	# store %rsiut\n"
"	movups %xmm0, (%r8)\n"
"	ret"

);

typedef struct __attribute__((aligned)) {
    uint32_t ekey[60]; // 4 * (ROUNDS + 1)
    uint32_t dkey[60];
    uint32_t klen;
} aes_key;

void aesni_set_key(aes_key *key, uint8_t *ukey, size_t len);
void aesni_cbc_enc(aes_key *key, uint8_t *dst, uint8_t *src, size_t len, uint8_t *iv);

void aes(uint8_t* in, uint8_t* out, uint8_t* in_key, uint8_t* iv){
	aes_key key = {{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
			0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
			0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
			0,0,0,0,0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
			0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
			0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
			0,0,0,0,0,0,0,0,0,0,0,0},1};
	aesni_set_key(&key, in_key, 16);
	aesni_cbc_enc(&key, out, in, 32, iv);
	return;
}
