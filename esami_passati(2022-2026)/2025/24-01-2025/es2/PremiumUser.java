import java.util.HashSet;
import java.util.Iterator;
import java.util.Set;
public class PremiumUser implements User, Comparable<PremiumUser> {
    private String username;
    private Set<User> follower;
    public PremiumUser(String username){
        this.username = username;
        this.follower = new HashSet<>();
    }
    @Override
    public String getUsername(){
        return this.username;
    }
    public void addFollower(User user){
        if(user == null)
            return;
        if(this.follower.contains(user))
            throw new SocialNetworkException("L'utente è già un follower di " + this.username);
        this.follower.add(user);
        /* oppure
        if(!this.follower.add(user))
            throw new SocialNetworkException("L'utente è già un follower di " + this.username);
        */
    }
    public Set<User> getFollower() {
        return new HashSet<>(this.follower);
    }
    @Override
    public boolean equals(Object obj){
        if(this == obj)
            return true;
        if(obj == null || getClass() != obj.getClass())
            return false;
        PremiumUser other = (PremiumUser) obj;
        return this.username.equals(other.username);
    }
    @Override
    public String toString(){
        return this.username;
    }
    @Override
    public int compareTo(PremiumUser other){
        return Integer.compare(this.follower.size(), other.follower.size());
    }
}
