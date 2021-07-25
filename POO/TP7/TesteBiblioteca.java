
public class TesteBiblioteca {
    public static void main(String[] args) {

        Biblioteca c = new Biblioteca("awesomeCarolinaCollection");
        Biblioteca f = new Biblioteca("ShittyNoBooksBibliotecaDoFraga");

        c.inserirLivro("Twilight");
        f.inserirLivro("Twilight");

        c.inserirLivro("New Moon");
        f.inserirLivro("New Moon");

        c.inserirLivro("Eclipse");
        f.inserirLivro("Eclipse");

        c.inserirLivro("Amanhecer");
        f.inserirLivro("Amanhecer");

        c.inserirLivro("O Grande Gatsby");
        c.inserirLivro("O Boneco de Neve");
        c.inserirLivro("Viagem ao Infinito");

        for (String l : c.livros) {
            if (f.temLivro(l)) {
                System.out.println("O Fraga tem o livro");
            } else {
                System.out.println("O Fraga não tem o livro");
            }
        }

        if (!c.equals(f))
            System.out.println("Obviamente são diferentes as bibliotecas");

        Biblioteca c2 = (Biblioteca) c.clone();

        c2.setNome("Copia de seguranca");

        c2.removerLivro("Viagem ao Infinito");

        System.out.println(c2);

    }
}