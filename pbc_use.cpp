#include"pbc_use.h"


//哈希函数
#define SHA256_ROTL(a,b) (((a>>(32-b))&(0x7fffffff>>(31-b)))|(a<<b))
#define SHA256_SR(a,b) ((a>>b)&(0x7fffffff>>(b-1)))
#define SHA256_Ch(x,y,z) ((x&y)^((~x)&z))
#define SHA256_Maj(x,y,z) ((x&y)^(x&z)^(y&z))
#define SHA256_E0(x) (SHA256_ROTL(x,30)^SHA256_ROTL(x,19)^SHA256_ROTL(x,10))
#define SHA256_E1(x) (SHA256_ROTL(x,26)^SHA256_ROTL(x,21)^SHA256_ROTL(x,7))
#define SHA256_O0(x) (SHA256_ROTL(x,25)^SHA256_ROTL(x,14)^SHA256_SR(x,3))
#define SHA256_O1(x) (SHA256_ROTL(x,15)^SHA256_ROTL(x,13)^SHA256_SR(x,10))
char* StrSHA256(const char* str, long long length, char* sha256) {
	char *pp, *ppend;
	long l, i, W[64], T1, T2, A, B, C, D, E, F, G, H, H0, H1, H2, H3, H4, H5, H6, H7;
	H0 = 0x6a09e667, H1 = 0xbb67ae85, H2 = 0x3c6ef372, H3 = 0xa54ff53a;
	H4 = 0x510e527f, H5 = 0x9b05688c, H6 = 0x1f83d9ab, H7 = 0x5be0cd19;
	long K[64] = {
		0x428a2f98, 0x71374491, 0xb5c0fbcf, 0xe9b5dba5, 0x3956c25b, 0x59f111f1, 0x923f82a4, 0xab1c5ed5,
		0xd807aa98, 0x12835b01, 0x243185be, 0x550c7dc3, 0x72be5d74, 0x80deb1fe, 0x9bdc06a7, 0xc19bf174,
		0xe49b69c1, 0xefbe4786, 0x0fc19dc6, 0x240ca1cc, 0x2de92c6f, 0x4a7484aa, 0x5cb0a9dc, 0x76f988da,
		0x983e5152, 0xa831c66d, 0xb00327c8, 0xbf597fc7, 0xc6e00bf3, 0xd5a79147, 0x06ca6351, 0x14292967,
		0x27b70a85, 0x2e1b2138, 0x4d2c6dfc, 0x53380d13, 0x650a7354, 0x766a0abb, 0x81c2c92e, 0x92722c85,
		0xa2bfe8a1, 0xa81a664b, 0xc24b8b70, 0xc76c51a3, 0xd192e819, 0xd6990624, 0xf40e3585, 0x106aa070,
		0x19a4c116, 0x1e376c08, 0x2748774c, 0x34b0bcb5, 0x391c0cb3, 0x4ed8aa4a, 0x5b9cca4f, 0x682e6ff3,
		0x748f82ee, 0x78a5636f, 0x84c87814, 0x8cc70208, 0x90befffa, 0xa4506ceb, 0xbef9a3f7, 0xc67178f2,
	};
	l = length + ((length % 64 > 56) ? (128 - length % 64) : (64 - length % 64));
	if (!(pp = (char*)malloc((unsigned long)l))) return 0;
	for (i = 0; i < length; pp[i + 3 - 2 * (i % 4)] = str[i], i++);
	for (pp[i + 3 - 2 * (i % 4)] = 128, i++; i < l; pp[i + 3 - 2 * (i % 4)] = 0, i++);
	*((long*)(pp + l - 4)) = length << 3;
	*((long*)(pp + l - 8)) = length >> 29;
	for (ppend = pp + l; pp < ppend; pp += 64) {
		for (i = 0; i < 16; W[i] = ((long*)pp)[i], i++);
		for (i = 16; i < 64; W[i] = (SHA256_O1(W[i - 2]) + W[i - 7] + SHA256_O0(W[i - 15]) + W[i - 16]), i++);
		A = H0, B = H1, C = H2, D = H3, E = H4, F = H5, G = H6, H = H7;
		for (i = 0; i < 64; i++) {
			T1 = H + SHA256_E1(E) + SHA256_Ch(E, F, G) + K[i] + W[i];
			T2 = SHA256_E0(A) + SHA256_Maj(A, B, C);
			H = G, G = F, F = E, E = D + T1, D = C, C = B, B = A, A = T1 + T2;
		}
		H0 += A, H1 += B, H2 += C, H3 += D, H4 += E, H5 += F, H6 += G, H7 += H;
	}
	free(pp - l);
	sprintf(sha256, "%08X%08X%08X%08X%08X%08X%08X%08X", H0, H1, H2, H3, H4, H5, H6, H7);
	return sha256;
}
char* FileSHA256(const char* file, char* sha256) {

	FILE* fh;
	char* addlp, T[64];
	long addlsize, j, W[64], T1, T2, A, B, C, D, E, F, G, H, H0, H1, H2, H3, H4, H5, H6, H7;
	long long length, i, cpys;
	void *pp, *ppend;
	H0 = 0x6a09e667, H1 = 0xbb67ae85, H2 = 0x3c6ef372, H3 = 0xa54ff53a;
	H4 = 0x510e527f, H5 = 0x9b05688c, H6 = 0x1f83d9ab, H7 = 0x5be0cd19;
	long K[64] = {
		0x428a2f98, 0x71374491, 0xb5c0fbcf, 0xe9b5dba5, 0x3956c25b, 0x59f111f1, 0x923f82a4, 0xab1c5ed5,
		0xd807aa98, 0x12835b01, 0x243185be, 0x550c7dc3, 0x72be5d74, 0x80deb1fe, 0x9bdc06a7, 0xc19bf174,
		0xe49b69c1, 0xefbe4786, 0x0fc19dc6, 0x240ca1cc, 0x2de92c6f, 0x4a7484aa, 0x5cb0a9dc, 0x76f988da,
		0x983e5152, 0xa831c66d, 0xb00327c8, 0xbf597fc7, 0xc6e00bf3, 0xd5a79147, 0x06ca6351, 0x14292967,
		0x27b70a85, 0x2e1b2138, 0x4d2c6dfc, 0x53380d13, 0x650a7354, 0x766a0abb, 0x81c2c92e, 0x92722c85,
		0xa2bfe8a1, 0xa81a664b, 0xc24b8b70, 0xc76c51a3, 0xd192e819, 0xd6990624, 0xf40e3585, 0x106aa070,
		0x19a4c116, 0x1e376c08, 0x2748774c, 0x34b0bcb5, 0x391c0cb3, 0x4ed8aa4a, 0x5b9cca4f, 0x682e6ff3,
		0x748f82ee, 0x78a5636f, 0x84c87814, 0x8cc70208, 0x90befffa, 0xa4506ceb, 0xbef9a3f7, 0xc67178f2,
	};
	fh = fopen(file, "rb");
	fseek(fh, 0, SEEK_END);
	length = _ftelli64(fh);
	addlsize = (56 - length % 64 > 0) ? (64) : (128);
	if (!(addlp = (char*)malloc(addlsize))) return 0;
	cpys = ((length - (56 - length % 64)) > 0) ? (length - length % 64) : (0);
	j = (long)(length - cpys);
	if (!(pp = (char*)malloc(j))) return 0;
	fseek(fh, -j, SEEK_END);
	fread(pp, 1, j, fh);
	for (i = 0; i < j; addlp[i + 3 - 2 * (i % 4)] = ((char*)pp)[i], i++);
	free(pp);
	for (addlp[i + 3 - 2 * (i % 4)] = 128, i++; i < addlsize; addlp[i + 3 - 2 * (i % 4)] = 0, i++);
	*((long*)(addlp + addlsize - 4)) = length << 3;
	*((long*)(addlp + addlsize - 8)) = length >> 29;
	for (rewind(fh); 64 == fread(W, 1, 64, fh);) {
		for (i = 0; i < 64; T[i + 3 - 2 * (i % 4)] = ((char*)W)[i], i++);
		for (i = 0; i < 16; W[i] = ((long*)T)[i], i++);
		for (i = 16; i < 64; W[i] = (SHA256_O1(W[i - 2]) + W[i - 7] + SHA256_O0(W[i - 15]) + W[i - 16]), i++);
		A = H0, B = H1, C = H2, D = H3, E = H4, F = H5, G = H6, H = H7;
		for (i = 0; i < 64; i++) {
			T1 = H + SHA256_E1(E) + SHA256_Ch(E, F, G) + K[i] + W[i];
			T2 = SHA256_E0(A) + SHA256_Maj(A, B, C);
			H = G, G = F, F = E, E = D + T1, D = C, C = B, B = A, A = T1 + T2;
		}
		H0 += A, H1 += B, H2 += C, H3 += D, H4 += E, H5 += F, H6 += G, H7 += H;
	}
	for (pp = addlp, ppend = addlp + addlsize; pp < ppend; pp = (long*)pp + 16) {
		for (i = 0; i < 16; W[i] = ((long*)pp)[i], i++);
		for (i = 16; i < 64; W[i] = (SHA256_O1(W[i - 2]) + W[i - 7] + SHA256_O0(W[i - 15]) + W[i - 16]), i++);
		A = H0, B = H1, C = H2, D = H3, E = H4, F = H5, G = H6, H = H7;
		for (i = 0; i < 64; i++) {
			T1 = H + SHA256_E1(E) + SHA256_Ch(E, F, G) + K[i] + W[i];
			T2 = SHA256_E0(A) + SHA256_Maj(A, B, C);
			H = G, G = F, F = E, E = D + T1, D = C, C = B, B = A, A = T1 + T2;
		}
		H0 += A, H1 += B, H2 += C, H3 += D, H4 += E, H5 += F, H6 += G, H7 += H;
	}
	free(addlp); fclose(fh);
	sprintf(sha256, "%08X%08X%08X%08X%08X%08X%08X%08X", H0, H1, H2, H3, H4, H5, H6, H7);
	return sha256;
}
//setup
pairing_t pairing;

element_t g, h, g2;
element_t A, x, Y, B1, B2;
element_t u1, u2, v1, v2, g1;
element_t pk[14];
element_t sk[5];
element_t zhuSK;
void setup() {
	char** argv = new char*[2];
	argv[1] = const_cast<char*>("error");
	pbc_demo_pairing_init(pairing, 2, argv);
	if (!pairing_is_symmetric(pairing)) pbc_die("pairing must be symmetric");
	//生成元
	element_init_G1(g, pairing);
	element_init_G1(h, pairing);
	element_init_G1(g2, pairing);
	element_random(g);
	element_random(h);
	element_random(g2);
	//element_printf("g2 = %B\n", g2);
	//五个随机数
	element_init_Zr(A, pairing);
	element_init_Zr(x, pairing);
	element_init_Zr(Y, pairing);
	element_init_Zr(B1, pairing);
	element_init_Zr(B2, pairing);
	element_random(A);
	element_random(x);
	element_random(Y);
	element_random(B1);
	element_random(B2);

	element_init_G1(u1, pairing);
	element_init_G1(u2, pairing);
	element_init_G1(v1, pairing);
	element_init_G1(v2, pairing);
	element_init_G1(g1, pairing);

	element_pow_zn(u1, g, B1);
	element_pow_zn(u2, g, B2);
	element_pow_zn(v1, h, B1);
	element_pow_zn(v2, h, B2);
	element_pow_zn(g1, g, Y);

	int len = element_length_in_bytes(g);
	char* strA = (char*)malloc(len * sizeof(char) * 4);
	element_snprint(strA, len * sizeof(char) * 4, g);

	//公钥生成
	for (int i = 0; i < 14; i++)
		element_init_G1(pk[i], pairing);
	element_set(pk[0], g);
	element_set(pk[1], g1);
	element_set(pk[2], g2);
	element_pow_zn(pk[3], g, x);
	element_pow_zn(pk[4], g, A);
	element_t tmp;
	element_init_Zr(tmp, pairing);
	element_mul(tmp, A, A);
	element_pow_zn(pk[5], g, tmp);
	element_set(pk[6], u1);
	element_set(pk[7], v1);
	element_pow_zn(pk[8], v1, A);
	element_pow_zn(pk[9], v1, tmp);
	element_set(pk[10], u2);
	element_set(pk[11], v2);
	element_pow_zn(pk[12], v2, A);
	element_pow_zn(pk[13], v2, tmp);

	for (int i = 0; i < 4; i++)
		element_init_Zr(sk[i], pairing);
	element_set(sk[0], A);
	element_set(sk[1], x);
	element_set(sk[2], B1);
	element_set(sk[3], B2);
	element_init_G1(sk[4], pairing);
	element_set(sk[4], h);

	element_init_Zr(zhuSK, pairing);
	element_set(zhuSK, Y);
}
VAR var_back() {
	VAR result;
	int len = element_length_in_bytes(g);
	char* r1 = (char*)malloc(len * sizeof(char) * 4);
	element_snprint(r1, len * sizeof(char) * 4, g);
	result.g = (string)r1;
	len = element_length_in_bytes(A);
	char* r2 = (char*)malloc(len * sizeof(char) * 4);
	element_snprint(r2, len * sizeof(char) * 4, A);
	result.A = (string)r2;
	len = element_length_in_bytes(u1);
	char* r3 = (char*)malloc(len * sizeof(char) * 4);
	element_snprint(r3, len * sizeof(char) * 4, u1);
	result.u1 = (string)r3;
	len = element_length_in_bytes(u2);
	char* r4 = (char*)malloc(len * sizeof(char) * 4);
	element_snprint(r4, len * sizeof(char) * 4, u2);
	result.u2 = (string)r4;
	return result;
}

element_t r_user, r_vl;
SK_user keyGen(char* a) {
	//kenGen
	string timestamp = "1543295911";
	element_t Y1, Y2;

	element_init_Zr(Y2, pairing);
	element_init_Zr(Y1, pairing);
	element_init_Zr(r_user, pairing);

	element_random(Y1);
	element_sub(Y2, Y, Y1);

	element_random(r_user);

	SK_user sk;
	element_init_G1(sk.IK1, pairing);
	element_init_G1(sk.IK2, pairing);
	element_init_G1(sk.VK1, pairing);
	element_init_G1(sk.VK2, pairing);
	//IK部分
	element_t tmp;
	element_init_G1(tmp, pairing);
	element_pow_zn(tmp, g2, Y1);
	//H1哈希函数
	//char *a = new char('1');
	char sha256[256];
	StrSHA256(a, sizeof(a) - 1, sha256);
	//puts(sha256);
	element_t H2ID;
	element_init_G1(H2ID, pairing);
	element_from_hash(H2ID, sha256, 32);
	element_pow_zn(H2ID, H2ID, r_user);

	element_mul(H2ID, tmp, H2ID);
	element_set(sk.IK1, H2ID);

	element_pow_zn(tmp, g, r_user);
	element_set(sk.IK2, tmp);

	//VK部分
	element_init_Zr(r_vl, pairing);
	element_random(r_vl);

	element_t vk_tmp;
	element_init_G1(vk_tmp, pairing);
	element_pow_zn(vk_tmp, g2, Y2);

	//H2哈希函数
	StrSHA256(timestamp.c_str(), sizeof(timestamp.c_str()) - 1, sha256);
	//puts(sha256);
	element_t H2VI;
	element_init_G1(H2VI, pairing);
	element_from_hash(H2VI, sha256, 32);
	element_pow_zn(H2VI, H2VI, r_vl);
	element_mul(H2VI, vk_tmp, H2VI);
	element_set(sk.VK1, H2VI);
	element_pow_zn(vk_tmp, g, r_vl);
	element_set(sk.VK2, vk_tmp);

	return sk;
}
element_t s, t, ak, o, CID0, CID1, EID, EVI;
element_t F1A, F2A, FA;
string a[3] = { "apple","orangle","blue" };

TOKEN authorize(char *aaa) {
	string timestamp = "1543295911";
	element_t tmp, tmp1, tmp2, tmp3;

	element_init_Zr(F1A, pairing);
	element_init_Zr(F2A, pairing);
	element_init_Zr(FA, pairing);

	element_init_Zr(tmp, pairing);
	element_init_Zr(tmp1, pairing);
	element_init_Zr(tmp2, pairing);
	element_init_Zr(tmp3, pairing);

	const char *b1 = a[0].c_str();
	char sha256[256];
	StrSHA256(b1, sizeof(b1) - 1, sha256);
	element_from_hash(tmp1, sha256, 32);
	element_add(tmp1, tmp1, A);

	const char *b2 = a[1].c_str();
	StrSHA256(b2, sizeof(b2) - 1, sha256);
	element_from_hash(tmp2, sha256, 32);
	element_add(tmp2, tmp2, A);

	const char *b3 = a[2].c_str();
	StrSHA256(b3, sizeof(b3) - 1, sha256);
	element_from_hash(tmp3, sha256, 32);
	element_add(tmp3, tmp3, A);
	element_mul(tmp, tmp1, tmp2);
	element_mul(F1A, tmp, tmp3);

	element_set(F2A, tmp1);
	element_div(FA, F1A, F2A);


	struct CTID {
		element_t  CID0;
		element_t CID1;
		element_t EID;
		element_t EVI;
	};
	element_init_GT(s, pairing);
	element_init_Zr(t, pairing);
	element_t ak_tmp;
	element_init_G1(ak, pairing);
	element_init_Zr(ak_tmp, pairing);
	element_init_G1(o, pairing);

	element_init_GT(CID0, pairing);
	element_init_G1(CID1, pairing);
	element_init_G1(EID, pairing);
	element_init_G1(EVI, pairing);

	element_mul_zn(tmp, B1, B2);
	element_div(ak_tmp, tmp, FA);
	element_pow_zn(ak, h, ak_tmp);

	//o的生成
	element_random(s);
	int len11 = element_length_in_bytes(s);
	char* token11 = (char*)malloc(len11 * sizeof(char) * 4);
	element_snprint(token11, len11 * sizeof(char) * 4, s);
	string result6 = (string)token11;

	element_random(t);

	element_t ak_tmp1;
	element_init_G1(ak_tmp1, pairing);
	element_pow_zn(ak_tmp1, ak, s);
	int len = element_length_in_bytes(ak_tmp1);
	char* sA = (char*)malloc(len * sizeof(char) * 4);
	element_snprint(sA, len * sizeof(char) * 4, ak_tmp1);
	char *str = new char[strlen(sA) + strlen(timestamp.c_str()) + 1];
	strcpy(str, sA);
	strcat(str, timestamp.c_str());
	StrSHA256(str, sizeof(str) - 1, sha256);
	element_from_hash(o, sha256, 32);
	element_pow_zn(o, o, x);

	element_t pairing_tmp;
	element_init_GT(pairing_tmp, pairing);
	pairing_apply(pairing_tmp, g1, g2, pairing);

	element_pow_zn(CID0, pairing_tmp, t);
	element_mul(CID0, CID0, s);

	element_pow_zn(CID1, g, t);
	//char *aaa = new char('1');
	StrSHA256(aaa, sizeof(aaa) - 1, sha256);
	element_from_hash(EID, sha256, 32);
	element_pow_zn(EID, EID, t);

	StrSHA256(timestamp.c_str(), sizeof(timestamp.c_str()) - 1, sha256);
	element_from_hash(EVI, sha256, 32);
	element_pow_zn(EVI, EVI, t);
	//赋值
	TOKEN token;
	element_init_G1(token.ak, pairing);
	element_init_G1(token.o, pairing);
	element_init_GT(token.CID0, pairing);
	element_init_G1(token.CID1, pairing);
	element_init_G1(token.EID, pairing);
	element_init_G1(token.EVI, pairing);
	element_set(token.ak, ak);
	element_set(token.o, o);
	element_set(token.CID0, CID0);
	element_set(token.CID1, CID0);
	element_set(token.EID, EID);
	element_set(token.EVI, EVI);
	return token;


}
element_t C1, C2, C3;
C_TOTAL encrypt(string _g, string _a, string _u1, string _u2,string keyword) {
	element_t g, u1, u2;
	element_init_G1(g, pairing);
	element_init_G1(u1, pairing);
	element_init_G1(u2, pairing);
	element_set_str(g, _g.c_str(), 0);
	element_set_str(u1, _u1.c_str(), 0);
	element_set_str(u2, _u2.c_str(), 0);

	element_t r, r1, r2, F1IA;
	element_init_Zr(r, pairing);
	element_init_Zr(r1, pairing);
	element_init_Zr(r2, pairing);
	element_random(r);
	element_random(r1);
	element_sub(r2, r, r1);

	element_init_Zr(F1IA, pairing);
	element_set(F1IA, FA);
	element_printf("F1IA = %B\n", F1IA);
	element_printf("FA = %B\n", FA);

	element_init_G1(C1, pairing);
	element_init_G1(C2, pairing);
	element_init_G1(C3, pairing);
	element_t tmp;
	element_init_Zr(tmp, pairing);
	element_mul_zn(tmp, r, F1IA);
	element_pow_zn(C1, g, tmp);
	element_pow_zn(C2, u1, r2);
	element_pow_zn(C3, u2, r1);

	C_TOTAL result;
	int len = element_length_in_bytes(C1);
	char* sk1 = (char*)malloc(len * sizeof(char) * 4);
	element_snprint(sk1, len * sizeof(char) * 4, C1);
	result.C1 = (string)sk1;
	len = element_length_in_bytes(C2);
	char* sk2 = (char*)malloc(len * sizeof(char) * 4);
	element_snprint(sk2, len * sizeof(char) * 4, C2);
	result.C2 = (string)sk2;
	len = element_length_in_bytes(C3);
	char* vk1 = (char*)malloc(len * sizeof(char) * 4);
	element_snprint(vk1, len * sizeof(char) * 4, C3);
	result.C3 = (string)vk1;
	return result;

}
element_t T1, T2, T3;
void trapdoor(SK_user sk) {
	element_t stmp1, stmp2, stmp3, stmp4, s;
	//计算s
	element_init_GT(stmp1, pairing);
	element_init_GT(stmp2, pairing);
	element_init_GT(stmp3, pairing);
	element_init_GT(stmp4, pairing);
	element_init_GT(s, pairing);

	pairing_apply(stmp1, sk.IK2, EID, pairing);
	pairing_apply(stmp2, sk.VK2, EVI, pairing);
	element_mul(stmp1, stmp1, stmp2);
	element_mul(stmp1, stmp1, CID0);

	pairing_apply(stmp3, CID1, sk.IK1, pairing);
	pairing_apply(stmp4, CID1, sk.VK1, pairing);
	element_mul(stmp3, stmp3, stmp4);
	element_invert(stmp3, stmp3);

	element_mul(s, stmp1, stmp3);

	element_init_G1(T1, pairing);
	element_init_G1(T2, pairing);
	element_init_G1(T3, pairing);
	element_pow_zn(T1, ak, s);

	element_t tmp;
	element_t T2_tmp;
	element_init_Zr(tmp, pairing);
	element_init_GT(T2_tmp, pairing);
	char *aTrapdoor = const_cast<char*>(a[0].c_str());
	char sha256[256];
	StrSHA256(aTrapdoor, sizeof(aTrapdoor) - 1, sha256);
	element_from_hash(tmp, sha256, 32);
	element_add(tmp, tmp, A);
	element_div(tmp, F2A, tmp);
	element_mul_zn(T2_tmp, s, tmp);
	element_pow_zn(T2, v1, T2_tmp);
	element_pow_zn(T3, v2, T2_tmp);
}
bool test1() {
	element_t com1, com2;
	element_init_GT(com1, pairing);
	element_init_GT(com2, pairing);

	element_pairing(com1, o, g);

	element_t tmp1, tmp2;
	element_init_G1(tmp1, pairing);
	element_init_G1(tmp2, pairing);
	string a = "1543295911";
	int len = element_length_in_bytes(T1);
	char* sA = (char*)malloc(len * sizeof(char) * 4);
	element_snprint(sA, len * sizeof(char) * 4, T1);
	char *str = new char[strlen(sA) + strlen(a.c_str()) + 1];
	strcpy(str, sA);
	strcat(str, a.c_str());
	char sha256[256];
	StrSHA256(str, sizeof(str) - 1, sha256);
	element_from_hash(tmp1, sha256, 32);

	element_pow_zn(tmp2, g, x);
	element_pairing(com2, tmp1, tmp2);

	if (element_cmp(com1, com2) == 0) {
		return true;
	}
	else {
		return false;
	}

	
}
RESULT test2() {
	RESULT re;
	element_t test1, test2, tmp;
	element_init_GT(test1, pairing);
	element_init_GT(test2, pairing);
	element_init_GT(tmp, pairing);

	pairing_apply(test1, C1, T1, pairing);
	pairing_apply(tmp, C2, T3, pairing);
	pairing_apply(test2, C3, T2, pairing);
	element_mul(test2, test2, tmp);

	if (element_cmp(test1, test2) == 0) {
		re.result = true;
		int len = element_length_in_bytes(C1);
		char* t1 = (char*)malloc(len * sizeof(char) * 4);
		element_snprint(t1, len * sizeof(char) * 4, C1);
		re.C1 = (string)t1;
		len = element_length_in_bytes(C2);
		char* t2 = (char*)malloc(len * sizeof(char) * 4);
		element_snprint(t2, len * sizeof(char) * 4, C2);
		re.C2 = (string)t2;
		len = element_length_in_bytes(C3);
		char* t3 = (char*)malloc(len * sizeof(char) * 4);
		element_snprint(t3, len * sizeof(char) * 4, C3);
		re.C3 = (string)t3;
	}
	else {
		re.result = false;
		re.C1 = "";
		re.C2 = "";
		re.C3 = "";
	}
	return re;
}