<div align="center">
  <h1>C++ Module 06</h1> <img src="https://cdn-icons-png.flaticon.com/512/6132/6132222.png" alt="C++ Logo" width="65"></br></br>

</div>
<p align="center">
Bu modülde, C++'ta farklı cast türlerini öğrenerek tür dönüşümlerinin nasıl çalıştığını keşfedeceksiniz. static_cast, dynamic_cast ve reinterpret_cast gibi dönüşüm operatörlerini kullanarak veri türleri arasında güvenli ve etkili geçişler yapmayı öğreneceksiniz. Ayrıca, dynamic_cast ile polymorphism kavramını daha iyi anlayarak, türetilmiş sınıflar arasında güvenli dönüşümler gerçekleştireceksiniz.
</p>


### İçindekiler 📚
- [Ex00 - Conversion of scalar types](#conversion-of-scalar-types)
  - [Ex00 - Gereksinimleri](#ex00-gereksinimleri)
  - [Static Cast Nedir?](#static-cast-nedir)
  - [Şablon (Template) Nedir?](#template-nedir)
    - [Fonksiyon Şablonları (Function Templates)](#function-templates)
    - [Sınıf Şablonları (Class Templates)](#class-templates)
  - [Numeric Limits Nedir?](#numeric-limits-nedir)
- [Ex01 - Serialization](#serialization)
  - [Ex01 - Gereksinimleri](#ex01-gereksinimleri)
  - [Static Metod Nedir?](#static-metod)
  - [Reinterpret Cast Nedir?](#reinterpret-cast-nedir)
- [Ex02 - Identify real type](#identify-real-type)
  - [Ex02 - Gereksinimleri](#ex02-gereksinimleri)
  - [Dynamic Cast Nedir?](#dynamic-cast-nedir)

---

<a name="conversion-of-scalar-types"></a>
## Ex00 - Conversion of scalar types

Bu egzersizde, C++'ta bir sınıf `ScalarConverter` oluşturacak ve bu sınıfın yalnızca bir `statik` metodunu yazacaksınız: convert. Bu metod, bir C++ literal'inin `string` temsilini alacak ve şu dört `scalar` türüne dönüştürecektir:

- `char`
- `int`
- `float`
- `double`

<a name="ex00-gereksinimleri"></a>
### Ex00 - Gereksinimleri:

- **Sınıf Özellikleri:**

  - `ScalarConverter` sınıfı instansiyalanamaz (kullanıcılar tarafından örneği oluşturulamaz). Bu, yalnızca `statik` metod convert kullanılarak işlem yapılması gerektiği anlamına gelir.

- **Metod:**
  
  - `convert` `statik` metodu, `string` parametre olarak bir C++ literal’ini alacak ve bu değeri uygun türlerdeki değerlere dönüştürecektir.

- **Dönüşüm Türleri:**

  - `char`: Verilen değerin karakter türüne dönüştürülmesi.

  - `int`: Verilen değerin tam sayı türüne dönüştürülmesi.

  - `float`: Verilen değerin kayan nokta türüne (`float`) dönüştürülmesi.

  - `double`: Verilen değerin çift hassasiyetli kayan nokta türüne (`double`) dönüştürülmesi.

- **Özel Durumlar:**

  - **Char için:** Geçerli olmayan karakterler (görüntülenebilir olmayanlar) için bir hata mesajı gösterilecek.

  - **Pseudo literals:** `-inff`, `+inff`, `nanf` gibi değerler de işlenmeli.

  - **Dönüşüm Hataları:** Eğer dönüşüm mümkün değilse veya taşma durumu söz konusuysa, kullanıcıya bilgi veren bir mesaj yazdırılmalıdır.

- **İzin verilen Fonksiyonlar:**

  - String'den bir sayıya dönüşüm yapan her türlü fonksiyon kullanılabilir (örneğin, `std::stoi`, `std::stof`, `std::stod`).

- **Test Programı:**

  - `ScalarConverter` sınıfını test etmek için bir program yazılacaktır. Bu programda, kullanıcıdan alınan input, uygun türe dönüştürülecek ve her bir türdeki değer ekrana yazdırılacaktır.

  - ```sql
    ./convert 0
    char: Non displayable
    int: 0
    float: 0.0f
    double: 0.0
    
    ./convert nan
    char: impossible
    int: impossible
    float: nanf
    double: nan
    
    ./convert 42.0f
    char: '*'
    int: 42
    float: 42.0f
    double: 42.0

    ```

---

<a name="static-cast-nedir"></a>
### Static Cast Nedir?

`static_cast` C++ dilinde kullanılan bir tür dönüşüm operatörüdür. Derleme zamanında, türler arasında güvenli dönüşümler yapılmasını sağlar ve özellikle temel türler arasında dönüşümde kullanılır. `static_cast`, derleyici tarafından kontrol edilen ve hatasız dönüşümler sağlar, fakat yanlış bir dönüşüm yapılması durumunda derleme hatası alınır.

**Temel Özellikler:**

- **Derleme Zamanı Dönüşümü:** `static_cast`, dönüşüm işlemlerini derleme zamanında gerçekleştirir. Bu, dönüşümün tür güvenliğini sağlamak anlamına gelir ve hata yapma olasılığını azaltır.

- **Basit Dönüşümler:** Genellikle türler arasındaki temel dönüşümleri (örneğin, `int`'ten `float`'a, `double`'dan `int`'e) yapmak için kullanılır.

- **Veri Kaybı:** Dönüşüm sırasında veri kaybı yaşanabilir (örneğin, `double`'ı `int`'e dönüştürmek). Bu nedenle dikkatli kullanmak gerekir.

**Kullanım Alanları:**

- **Temel Veri Türleri:** `static_cast`, genellikle `char` ve `int` gibi temel veri türleri arasında dönüşüm yapmak için kullanılır.

- **Sınıflar Arasında Dönüşüm:** Aynı sınıf hiyerarşisine sahip nesneler arasında dönüşüm yapmak için de kullanılabilir. Ancak, bu durumda daha dikkatli olmak gerekmektedir.

**Örnek Kullanım:**

- ```cpp
    char ScalarConverter::toChar(int value) {
      // int türündeki 'value' değişkenini char türüne dönüştür
      char c = static_cast<char>(value);
  
      // Eğer değer char aralığının dışındaysa, dönüştürme mümkün değil
      if (value > numeric_limits<char>::max() || value < numeric_limits<char>::min())
          cout << "char: impossible" << endl;
      // Eğer karakter ekranda gösterilebilir bir karakter değilse
      else if (!isDisplayableChar(c))
          cout << "char: Non displayable" << endl;
      // Geçerli ve gösterilebilir bir karakterse, ekrana yazdır
      else
          cout << "char: '" << c << "'" << endl;
      return c;
  }
  ```

---

<a name="template-nedir"></a>
### Şablon (Template) Nedir?

C++'da şablonlar (`templates`), farklı veri türleriyle çalışabilen genel (`generic`) fonksiyonlar veya sınıflar yazmanızı sağlayan bir özelliktir. Şablonlar, kodunuzu daha esnek ve yeniden kullanılabilir hale getirir. Örneğin, aynı işlemi `int`, `double`, `string` gibi farklı türlerle yapmanız gerekiyorsa, her tür için ayrı fonksiyonlar yazmak yerine tek bir şablon kullanabilirsiniz.

Şablonlar iki ana kategoriye ayrılır:

- 1. Fonksiyon Şablonları (Function Templates)

- 2. Sınıf Şablonları (Class Templates)

<a name="function-templates"></a>
### Fonksiyon Şablonları (Function Templates)

Fonksiyon şablonları, farklı türlerle çalışabilen genel fonksiyonlar yazmanızı sağlar. Örneğin, iki sayıyı toplayan bir fonksiyon yazmak istiyorsunuz, ancak bu fonksiyon hem `int` hem de `double` türleriyle çalışsın. İşte bunun için fonksiyon şablonları kullanılır.

**Örnek: Fonksiyon Şablonu**

```cpp
#include <iostream>

// Fonksiyon şablonu tanımlanıyor
template <typename T>
T add(T a, T b) {
    return a + b;
}

int main() {
    // int türü ile kullanım
    std::cout << "Toplam (int): " << add(3, 5) << std::endl;

    // double türü ile kullanım
    std::cout << "Toplam (double): " << add(3.5, 2.7) << std::endl;

    return 0;
}
```

**Çıktı:**

```zsh
Toplam (int): 8
Toplam (double): 6.2
```

**Açıklama:**
- `template <typename T>`, şablonun başladığını belirtir. `T`, bir tür parametresidir (placeholder).

- `T add(T a, T b)`, `T` türünden iki parametre alır ve `T` türünden bir değer döndürür.

- `add(3, 5)` çağrıldığında `T` otomatik olarak int olur.

- `add(3.5, 2.7)` çağrıldığında `T` otomatik olarak double olur.

---


<a name="class-templates"></a>
### Sınıf Şablonları (Class Templates)

Sınıf şablonları, farklı türlerle çalışabilen genel sınıflar yazmanızı sağlar. Örneğin, bir dizi (array) sınıfı yazmak istiyorsunuz, ancak bu sınıf hem int hem de double türleriyle çalışsın. İşte bunun için sınıf şablonları kullanılır.

**Örnek: Sınıf Şablonu**

```cpp
#include <iostream>

// Sınıf şablonu tanımlanıyor
template <typename T>
class Box {
private:
    T value;
public:
    Box(T v) : value(v) {}
    T getValue() const {
        return value;
    }
};

int main() {
    // int türü ile kullanım
    Box<int> intBox(123);
    std::cout << "intBox değeri: " << intBox.getValue() << std::endl;

    // double türü ile kullanım
    Box<double> doubleBox(45.67);
    std::cout << "doubleBox değeri: " << doubleBox.getValue() << std::endl;

    return 0;
}
```

**Çıktı:**

```zsh
intBox değeri: 123
doubleBox değeri: 45.67
```

**Açıklama:**

- `template <typename T>`, şablonun başladığını belirtir. `T`, bir tür parametresidir.

- `Box<int> intBox(123);` ile `T` türü int olur.

- `Box<double> doubleBox(45.67);` ile `T` türü double olur.

**Not:**

- **Fonksiyon Şablonları:** Farklı türlerle çalışabilen genel fonksiyonlar yazmanızı sağlar.

- **Sınıf Şablonları:** Farklı türlerle çalışabilen genel sınıflar yazmanızı sağlar.

---


<a name="numeric-limits-nedir"></a>
### Numeric Limits Nedir?

`numeric_limits`, sayı türlerinin sınırlarını sorgulamak için kullanılan bir şablon sınıfıdır. Bu sınıf, bir türün alabileceği en küçük ve en büyük değeri, hassasiyet gibi özellikleri verir. Özellikle sayısal hesaplamalarda taşma (overflow) veya hassasiyet kontrolü için kullanılır.

**Temel Özellikleri:**

- **`Minimum` ve `Maksimum` Değerler**: numeric_limits sınıfı, belirli bir türün alabileceği en küçük ve en büyük değerleri döndüren metotlar sunar.

- `std::numeric_limits<T>::min()` — Türün alabileceği en küçük değeri verir.

- `std::numeric_limits<T>::max()` — Türün alabileceği en büyük değeri verir.

- **Epsilon**: Sayısal hassasiyetle ilgili bir değer sağlar. Örneğin, `std::numeric_limits<float>::epsilon()` fonksiyonu, float türünün en küçük pozitif farkını verir.

- **Düzenlilik ve Taşma**: Sayısal türlerin taşma (overflow) ve sıfırla bölme gibi özel durumlar için özelliklere de erişilebilir.

**Örnek Kullanım:**

```cpp
#include <iostream>
#include <limits>

int main() {
    std::cout << "int min: " << std::numeric_limits<int>::min() << std::endl;
    std::cout << "int max: " << std::numeric_limits<int>::max() << std::endl;
    std::cout << "float epsilon: " << std::numeric_limits<float>::epsilon() << std::endl;

    return 0;
}

```

---

<a name="serialization"></a>
## Ex01 - Serialization

Bu alıştırma (Exercise 01), serileştirme (`serialization`) ve ters serileştirme (`deserialization`) işlemlerini gerçekleştiren bir `Serializer` sınıfı yazmanızı istiyor. Ayrıca, bu sınıfın doğru çalıştığını test eden bir program yazmanız gerekiyor. 

<a name="ex01-gereksinimleri"></a>
### Ex01 - Gereksinimleri:

İşte adım adım ne yapmanız gerektiği:

**1. Serializer Sınıfını Oluştur**

- `Serializer` sınıfı, kullanıcı tarafından hiçbir şekilde örneklenemez (`initializable`) olmamalıdır. Yani, sınıfın constructor'ları private olmalıdır.

- Sınıf, iki `static` metoda sahip olmalıdır:

  - `uintptr_t serialize(Data* ptr);`: Bir `Data pointer`'ını alır ve onu `uintptr_t` türüne (işaretsiz bir tamsayı türü) dönüştürür.

  - `Data* deserialize(uintptr_t raw);`: Bir `uintptr_t` türündeki değeri alır ve onu `Data*` türüne (yani bir Data pointer'ına) dönüştürür.

**2. Data Yapısını Oluştur**

- `Data` adında bir yapı (`struct`) veya sınıf (`class`) oluşturun. Bu yapı boş olmamalıdır, yani en az bir veri üyesine (data member) sahip olmalıdır. Örneğin:

- ```cpp
  struct Data {
      int a;
      double b;
  };
  ```

**3. Test Programını Yaz**

- `main` fonksiyonunda aşağıdaki adımları takip edin:

  - Bir `Data` nesnesi oluşturun ve içine veri atayın.

  - Bu nesnenin adresini `serialize()` fonksiyonuna gönderin ve dönen `uintptr_t` değerini kaydedin.

  - Bu `uintptr_t` değerini `deserialize()` fonksiyonuna gönderin ve dönen `Data*` pointer'ını kaydedin.

  - Orijinal pointer ile `deserialize()` sonucu dönen pointer'ın aynı adresi gösterdiğini kontrol edin.

  - Data nesnesinin veri üyelerini ekrana yazdırarak doğru çalıştığını doğrulayın.

---

<a name="static-metod"></a>
### Static Metod Nedir?

`static` metodlar, belirli bir sınıfın üyesi olan ancak o sınıfın belirli bir nesnesine bağlı olmayan metodlardır. Yani, `static metodlar` nesne oluşturmadan çağrılabilir. Bunun sebebi, static metodların sınıf düzeyinde tanımlanması ve sınıfın herhangi bir örneğine (instance) bağlı olmamasıdır.

- **Nesneye Bağlı Değildir:** `Static metodlar`, sınıfa ait olup belirli bir nesneye ihtiyaç duymaz.

- **Sadece Static Üyelere Erişebilir:** `Static metodlar`, sınıf içindeki yalnızca `static` değişkenlere ve diğer static metodlara erişebilir.

- **Sınıf Adı ile Çağrılır:** Bir nesne oluşturmadan, doğrudan sınıf adı üzerinden çağrılır:
  - `SinifAdi::MetodAdi();`

- **this Pointer'ı Kullanamaz:** `Static metodlar` nesneye bağlı olmadığı için `this` pointer'ı içermez.

---

<a name="reinterpret-cast-nedir"></a>
### Reinterpret Cast Nedir?

`reinterpret_cast`, C++'da kullanılan bir tür dönüşüm (`type casting`) operatörüdür. Bu operatör, bir türü tamamen farklı bir türe dönüştürmek için kullanılır. Ancak, diğer tür dönüşüm operatörlerinden (örneğin, `static_cast`, `dynamic_cast`, `const_cast`) farklı olarak, `reinterpret_cast` çok daha güçlü ve tehlikeli bir operatördür. Çünkü bu operatör, derleyiciye "bu veriyi başka bir tür olarak yorumla" der ve herhangi bir tür kontrolü yapmaz.

`reinterpret_cast` aşağıdaki durumlarda kullanılır:

- **Pointer Türleri Arasında Dönüşüm:** Bir pointer'ı başka bir pointer türüne dönüştürmek.

  - Örneğin, `int*` türündeki bir pointer'ı `double*` türüne dönüştürmek.

- **Pointer ile Tamsayı Arasında Dönüşüm:** Bir pointer'ı tamsayıya veya bir tamsayıyı pointer'a dönüştürmek.

  - Örneğin, bir pointer'ın bellek adresini `uintptr_t` türünde bir tamsayıya çevirmek.

- **Farklı Türler Arasında Dönüşüm:** İlişkisiz türler arasında dönüşüm yapmak.

  - Örneğin, bir sınıf pointer'ını tamamen farklı bir sınıf pointer'ına dönüştürmek.

---

Bu README dosyası Derya ACAR tarafından hazırlanmıştır.
