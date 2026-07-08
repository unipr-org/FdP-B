import java.util.HashSet;
import java.util.Set;
public class SocialNetwork {
    private String nomeSocial;
    private Set<User> iscritti;
    public SocialNetwork(String nomeSocial){
        this.nomeSocial = nomeSocial;
        this.iscritti = new HashSet<>();
    }
    public String getNomeSocial(){
        return this.nomeSocial;
    }
    public Set<User> getIscritti(){
        return new HashSet<>(this.iscritti);
    }
    public void addUser(User user){
        if(user == null)
            return;
        if(this.iscritti.contains(user))
            throw new SocialNetworkException("L'utente è già iscritto a questo social network!");
        this.iscritti.add(user);
    }
}
