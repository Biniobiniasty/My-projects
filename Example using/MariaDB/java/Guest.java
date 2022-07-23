import javax.persistence.Entity;
import javax.persistence.GeneratedValue;
import javax.persistence.GenerationType;
import javax.persistence.Id;

@Entity // adnotacja ze bedziemy obiekt zapisywac w bazie danych
public class Guest {

    @Id // adnotacji id bo bedzie to wartosc id dla tej klasy
    @GeneratedValue(strategy = GenerationType.AUTO) // automatyczne generowanie pola
    private long id;

    private String name;
    private int age;

    public Guest() {



    }

    public Guest(String name, int age) {
        this.name = name;
        this.age = age;
    }

    public long getId() {
        return id;
    }

    public void setAge(int newAge) {
        this.age = newAge;
    }
}
