# 🔐 Beecrowd 1412 — Cadeado com Segredo

Solução do problema [1412 - Cadeado com Segredo](https://www.beecrowd.com.br/judge/pt/problems/view/1412) da plataforma Beecrowd, utilizando linguagem C.

---

## 🧩 Sobre o problema

O problema simula um cadeado circular com letras do alfabeto (`'a'` até `'z'`). A sequência começa em `'a'`, percorre uma cadeia de letras fornecida na entrada e deve retornar a `'a'` no final. A tarefa é calcular o número mínimo de rotações necessárias para realizar esse ciclo, considerando as diferenças modulares entre letras consecutivas.

📌 A entrada contém várias cadeias de letras, uma por linha, e termina com uma linha contendo apenas um asterisco (`*`).  
📌 Para cada linha, deve-se imprimir a quantidade mínima de rotações necessárias para fechar o cadeado.

---

## 📦 Estrutura da solução

- Cálculo das diferenças modulares entre letras, incluindo:
  - `'a'` para a primeira letra
  - Entre letras da sequência
  - Da última letra de volta para `'a'`
- Ordenação das diferenças
- Simulação da redistribuição das rotações usando operações modulares para minimizar o total de movimentos

---

## ⚙️ Como compilar e executar

### 💻 Linux / Mac:

```bash
gcc main.c -o cadeado
./cadeado
