public class Partito implements Eleggibile, Cloneable {
    private String nome;
    private int voti;

    public Partito(String nome) {
        this.nome = nome;
        this.voti = 0;
    }

    public void vota() {
        this.voti++;
    }

    @Override
    public String getNome() { return this.nome; }

    @Override
    public int getVoti() { return this.voti; }

    @Override
    public boolean equals(Object obj) {
        if (this == obj) return true;
        if (obj == null || getClass() != obj.getClass()) return false;
        Partito other = (Partito) obj;
        return this.nome.equals(other.nome) && this.voti == other.voti;
    }

    @Override
    public String toString() {
        return "Partito{nome='" + nome + "', voti=" + voti + "}";
    }
}