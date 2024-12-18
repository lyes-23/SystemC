# Compilation du miniriscv.
Pour compiler le miniriscv pour la premi`ere fois, lancez les commandes suivantes:
```bash
scl enable devtoolset-8 bash
source ~massoc/bin/systemc-env.sh-2023
make clean && make -j

```
# Compilation d’un fichier de test
Tout d'abord il faut compiler le fichier **reset** qui initialise la pile, et saute vers le main qui devrait definir par le programme de test. Ce programme d´efinit aussi deux fonctions, *_good* et *_bad*, qui permettent
de sortir de la simulation selon le r´esultat d’un test.

```bash
riscv32-unknown-elf-gcc -nostdlib -c SW/reset.s -o reset.o -march=rv32imad
```
or 

```bash
riscv32-unknown-elf-gcc -nostdlib -c SW/reset.s -o reset.o -march=rv32imad
```
depends on the machines 

Puis, il faut générer le .o de votre test, avec la commande:

```bash
riscv32-unknown-elf-gcc -nostdlib -c [votre fichier] -o app.o -march=rv32imad
```
En remplacant [votre fichier] par le nom du fichier que vous souhaitez compiler.

Enfin, il faut linker ces deux fichiers, avec un fichier d’édition de lien spécial.
Cela correspond a la commande :
```bash
riscv32-unknown-elf-gcc -nostdlib reset.o app.o -T SW/link.ld -o app -march=rv32imad
```

Cela vous génère un exécutable risc-v nommé app. Vous pourrez lancer la
simulation sur ce fichier de la mani`ere suivante :

```bash
/run.exe app
```