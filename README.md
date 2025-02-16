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


---

Bu README dosyası Derya ACAR tarafından hazırlanmıştır.
