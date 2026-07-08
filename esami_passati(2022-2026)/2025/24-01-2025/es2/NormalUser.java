import java.util.Set;
import java.util.HashSet;
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
    public void addFriend(User user){
        if(this.equals(user))
            throw new SocialNetworkException("Impossibile aggiungere se stessi agli amici");
        if(user != null)
            this.amici.add(user);
    }
    public void follow(PremiumUser pu){
        if(pu != null)
            pu.addFollower(this);
    }
    @Override
    public String getUsername(){
        return this.nome + this.cognome + this.amici.size();
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
    public String toString(){
        return this.getUsername();
    }
}
