# Gestion Bancaire Multi-Devises (C++)

Projet C++ simulant un systeme de gestion de comptes bancaires avec conversion automatique de devises.

## Fonctionnalités
* **Classes & Héritage** : `Compte` classique et `CompteLimite` (avec plafond).
* **Devises** : Gestion dynamique EUR/USD/JPY via la classe `Money`.
* **Polymorphisme** : Gestion centralisée via la classe `Banque`.

## Structure
* `main.cpp` : Scénario de test.
* `Money.h/cpp` : Surcharge d'opérateurs et taux de change.
* `Banque.h/cpp` : Conteneur de comptes.

## Compilation et Execution
```bash
make
./gestion_banque
