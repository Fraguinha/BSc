public class FrascoChocolates {
    int capacidade, conteudo;

    public FrascoChocolates(int cap, int cont) {
        capacidade = cap;
        conteudo = cont;
    }

    public void retira(int quantidade) throws FrascoVazio {
        if (this.conteudo < quantidade)
            throw new FrascoVazio("OH! OH! guloso, queres demais " + capacidade + " " + conteudo);
        this.conteudo -= quantidade;
    }

    public void enche(int quantidade) throws FrascoCheio {
        if (this.conteudo + quantidade > this.capacidade)
            throw new FrascoCheio("OH! OH! já chega, estou de dieta " + capacidade + " " + conteudo);
        this.conteudo += quantidade;
    }
}