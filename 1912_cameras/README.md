# 🎥 Beecrowd 1912 — Câmeras

Solução do problema [1912 - Câmeras](https://www.beecrowd.com.br/judge/pt/problems/view/1912), resolvido em linguagem C.

---

## 🧩 Sobre o problema

Dado um corredor de comprimento `L` e altura `A`, e um conjunto de câmeras com posições e alcances, o objetivo é determinar a menor quantidade de câmeras necessárias para cobrir todo o corredor.

Uma câmera cobre uma região circular, então é necessário usar trigonometria para calcular a projeção horizontal (intervalo coberto no chão) que consegue atingir uma altura `A`.

---

## 📦 Estratégia da Solução

- Desconsidera câmeras que não cobrem a altura `A`
- Calcula a projeção horizontal de cada câmera usando:

horizontal = sqrt(r² - (A/2)²)

- Ordena os intervalos por início
- Usa **algoritmo guloso** para cobrir o corredor com o menor número possível de intervalos

---

## ⚙️ Como compilar e executar

### 💻 Linux / Mac:

```bash
gcc main.c -o cameras
./cameras

