import java.util.ArrayList;

public class Biblioteca {

    private String nome;
    ArrayList<String> livros;

    public Biblioteca() {
        nome = "";
        livros = new ArrayList<String>();
    }

    public Biblioteca(String nome) {
        this.nome = nome;
        livros = new ArrayList<String>();
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public void setLivros(ArrayList<String> livros) {
        this.livros = livros;
    }

    public String getNome() {
        return nome;
    }

    public ArrayList<String> getLivros() {
        return livros;
    }

    public String toString() {
        String s = "Nome da Biblioteca: " + nome + " ";
        s += livros.toString();
        return s;
    }

    public boolean equals(Object obj) {
        if (obj == this)
            return true;
        if (obj != null && obj instanceof Biblioteca) {
            Biblioteca b = (Biblioteca) obj;
            if (b.getNome().equals(this.nome) && b.getLivros().equals(this.livros)) {
                return true;
            }
        }
        return false;
    }

    public Object clone() {
        Biblioteca b = new Biblioteca(this.nome);
        b.setLivros((ArrayList<String>) livros.clone());
        return (Object) b;
    }

    public boolean temLivro(String livro) {
        for (String s : this.livros) {
            if (s.equals(livro)) {
                return true;
            }
        }
        return false;
    }

    public void inserirLivro(String livro) {
        if (!this.temLivro(livro)) {
            this.livros.add(livro);
        }
    }

    public void removerLivro(String livro) {
        this.livros.remove(livro);
    }
}