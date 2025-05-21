# Game of Life - SFML Project

Ce projet utilise SFML 2.6 avec C++23, compilé sous Windows avec MinGW-w64 via MSYS2.

---

## Prérequis pour compiler et exécuter le projet

### 1. Installer MSYS2 (pour le compilateur et les outils)

- Télécharger MSYS2 ici :  
  [https://www.msys2.org/](https://www.msys2.org/)

- Installer MSYS2 puis lancer le terminal `MSYS2 MinGW 64-bit` (important pour compiler en 64 bits).

- Mettre à jour les paquets :
  ```bash
  pacman -Syu
  ```

- Installer le compilateur GCC MinGW 64-bit et Ninja :
  ```bash
  pacman -S mingw-w64-x86_64-gcc mingw-w64-x86_64-ninja
  ```

---

### 2. Installer SFML 2.6

- Télécharger SFML 2.6 (MinGW 64-bit) :  
  [https://www.sfml-dev.org/download/sfml/2.6.0/](https://www.sfml-dev.org/download/sfml/2.6.0/)

- Extraire SFML dans `C:/SFML` (ou modifier le chemin `SFML_ROOT` dans `CMakeLists.txt` si nécessaire).

---

### 3. Installer CMake (version 3.30 ou plus)

- Télécharger CMake :  
  [https://cmake.org/download/](https://cmake.org/download/)

- Ajouter CMake à la variable d'environnement PATH pour pouvoir l'utiliser dans un terminal.

---

### 4. Configurer et compiler le projet

  FILE -> RELOAD CMAKE Project pour créer et tout le fichier de build 

- Ouvrir `MSYS2 MinGW 64-bit` terminal.

- Se placer dans le dossier racine du projet (`game_of_life`).

- Créer un dossier de build et lancer CMake :
  ```bash
  mkdir build
  cd build
  cmake -G Ninja ..
  ninja
  ```

- L’exécutable `game_of_life.exe` et les DLL nécessaires seront générés dans le dossier `build`.

---

### 5. Exécuter le projet

- Dans le dossier `build`, lancer `./game_of_life.exe`.

- Les DLL SFML et MinGW doivent être présentes dans ce dossier (cette étape est automatisée par le `CMakeLists.txt`).

---

## Notes

- Assurez-vous que le dossier `assets` est présent dans le dossier racine du projet pour que les ressources soient copiées lors de la compilation.

- Si vous modifiez le chemin d’installation SFML ou MSYS2, pensez à mettre à jour `CMakeLists.txt`.

---

## Liens utiles

- MSYS2 : https://www.msys2.org/
- SFML 2.6 (MinGW 64-bit) : https://www.sfml-dev.org/download/sfml/2.6.0/
- CMake : https://cmake.org/download/

---

Si vous rencontrez des problèmes, vérifiez bien que toutes les DLL sont copiées dans le dossier build, et que vous compilez en 64 bits avec le même compilateur que SFML.

---

Bon codage ! 🚀
