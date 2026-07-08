import java.security.Permission;
import java.util.HashSet;
import java.util.Set;
public class NormalUser implements User{
    private String nome;
    private String cognome;
    private Set<User> amici;
    public NormalUser(String nome, String cognome){
        this.nome = nome;
        this.cognome = cognome;
        this.amici = new HashSet<>();
    }
    public String getNome(){
        return this.nome;
    }
    public String getCognome(){
        return this.cognome;
    }
    public Set<User> getAmici(){
        return new HashSet<>(this.amici);
    }
    @Override
    public String getUsername(){
        return this.nome + this.cognome + this.amici.size();
    }
    public void addFriend (User user){
        if (user == null)
            return;
        if (user.equals(this))
            throw new SocialNetworkException("Un utente non puo' aggiungere se stesso come amico.");
        this.amici.add(user);
    }
    public void follow(PremiumUser pu){
        if (pu == null) return;
        if (pu.getFollower().contains(this))
            throw new SocialNetworkException("Segui gia' questo utente Premium.");
        pu.addFollower(this);
    }
    @Override
    public boolean equals(Object obj) {
        if (this == obj)
            return true;
        if (obj == null || getClass() != obj.getClass())
            return false;
        NormalUser other = (NormalUser) obj;
        return this.nome.equals(other.nome) && this.cognome.equals(other.cognome);
    }
    @Override
    public String toString() {
        return this.getUsername();
    }
}
