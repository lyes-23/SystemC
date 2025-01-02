.global main
main:
    # Initialisation des registres
    li   s2, 16          # Valeur initiale : 16 (0b00010000)
    li   x6, 32          # Résultat attendu pour slli (16 << 1 = 32)
    li   x7, 8           # Résultat attendu pour srli (16 >> 1 = 8)
    li   x8, 8           # Résultat attendu pour srai (16 >> 1 = 8, car positif)

    # Test de slli (Shift Left Logical)
    slli x3, s2, 1       # Décalage gauche logique de s2 de 1 bit
    bne  x3, x6, _slli_fail  # Si x3 != 32, le test échoue

    # Test de srli (Shift Right Logical)
    srli x4, s2, 1       # Décalage droit logique de s2 de 1 bit
    bne  x4, x7, _srli_fail  # Si x4 != 8, le test échoue

    # Test de srai (Shift Right Arithmetic)
    srai x5, s2, 1       # Décalage droit arithmétique de s2 de 1 bit
    bne  x5, x8, _srai_fail  # Si x5 != 8, le test échoue

    # Tous les tests réussis
    j _good           # Saute à la fin si tout est correct

_slli_fail:
    j _bad              

_srli_fail:
    j _bad              

_srai_fail:
    j _bad             

_good:
    nop                  # Point d'arrêt si tous les tests réussissent
    j _end               # Fin du programme

_bad:
    nop                  # Point d'arrêt si un test échoue

_end:
    nop                  # Fin du programme
