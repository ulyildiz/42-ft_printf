## **Va_ Fonksiyonları**
Variadic Function olarak geçen bu arkadaşlar "va_start", "va_arg", "va_end", "va_cpy"dir. Bu fonksiyonlar va_list structında değişken alır. 
### **va_list**
va_list belirsiz veri tipli belirsiz sayıdaki argüman alan fonksiyonlarda kullanılan veri tipidir. 

		unsigned int gp_offset;
		unsigned int fp_offset;
		void *overflow_arg_area;
		void *reg_save_area;
va_list structı ise yukarıdaki gibidir(İşlemci mimarisi göre değişebilir.). 
#### **reg_save_area**
Register save area işlemcideki çalışma anında registerlara atanmış geçici verilerin saklandığı yerdir. Program çalışırken belirli sayıda register tutulabilir ve bu sayı işlemci mimarisine göre değişir. 

#### **overflow_arg_area**
Overflow argument area işlemcide reg_save_areadan taşan argümanların tutulduğu bölgedir.

Bu iki alan da çoğu zaman C derleyicileri tarafından arkaplanda kullanılır. Bulabildiğim sebepleri ise genel anlamda registerlarda geçici saklanmış değerleri çekme daha hızlı ve kolay kılınmıştır. 

Offset -> bir mesafe göstergesidir. Bir nesnenin başlangıç değerinden bir sonraki noktaya kadar olan tam sayıdır.
#### **gp_offset** (General purpose offset)
Genel amaçlı registerlar(GPR) genel amaçlı veri tipleri(char, int, short, long, adresler ..) için kullanılanlardır. Her bir register 8 bytedır. 

#### **fp_offset** (Float Point offset)
Kayan işaretçi registerlar(FPR) özelleştirilmiş bir şekilde float sayılar için kullanılanlardır. Her bir registeri ise 16 bytetır.

### **va_start**
va_start ise değişken argümanlara başlamadan hemen önceki initialize eder.
Bu başlatma işlemleri, genellikle argümanlar stackte olduğundan o frame e eriştirebilir. İlk variadiz argumanla son arasında ofseti hesaplar. İlk argümana işaretçi ayarlar ve derşeyice özgü işlemler optimizasyon (varsa)gerçekleşir.

### **va_arg**
va_arg aldığı 2 değişken ile (va_list argümanı, type) argümanları atlar. başlangıç adresi elinde olduğu için girdiğimiz type'a göre nerede bitireceğini belirler ve block block işlemini uygular.

### **va_end**
va_end ise ise va_list yapısını geçersiz kılar(cleanup işlemlerine sokar) reinitialize edilmesi gerekir.
Cleanup olarak dahili bir veri yapısı olduğundan işaretçileri/bayrakları sıfırlar. Derleyice özgü temizleme işlemleri varsa yapabilir. Stackta veya geçiçi veri yapılarında(register(?)) yapının kullandığı yerleri resetleyebilir(?). 
