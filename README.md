# 🕹️ so_long

`so_long`, Ecole 42'nin grafik kütüphanesi MiniLibX kullanılarak geliştirilen bir 2D oyun projesidir. Oyuncu, harita üzerinde karakterini yönlendirerek tüm coinleri toplamalı ve çıkışa ulaşmalıdır.

## 🗺️ Oyun İçeriği

- `1`: Duvar  
- `0`: Boşluk  
- `P`: Oyuncu  
- `C`: Coin  
- `E`: Çıkış

## 🛠️ Derleme

```bash
make
````

> MiniLibX yüklü değilse kurmanız gerekir (Linux için `mlx` dizini dahil edilmeli).

## 🚀 Kullanım

```bash
./so_long maps/map.ber
```

## 🎮 Kontroller

* W / A / S / D: Hareket
* ESC: Oyunu kapat

## 📚 Öğrenilenler

* MiniLibX ile grafik programlama
* Harita işleme ve validasyon
* Oyun döngüsü, input handling
* Basit collision detection
