import javax.persistence.EntityManager;
import javax.persistence.EntityManagerFactory;
import javax.persistence.Persistence;

public class Main {

    public static void main(String[] args) {
        GuestRepository repo = new GuestRepository();

        System.out.println("------------------ CREATE -----------------");

        // Zapis danych do bazy
        repo.createNewGuest("Pawel", 34);
        repo.createNewGuest("Magda", 23);
        repo.createNewGuest("Kasia", 22);


        System.out.println("----------------- DOWNLOAD ------------------");
        // Wyszukanie (obiekt zwroci nam odrazu bez zapytania do bazy bo po tworzeniu [create] obiekty znajduja sie w entity manage-rze i te na zapoda)
        Guest g = repo.findById(1L);
        System.out.println(g.getId());


        // Nowa funkcja w ktorej dalismy em.clear() co wyczyscilo entyt manager mozna w konsoli zaobserwowac zapytania do bazy ktore pobiera dane o encji
        // Wymagany jest tutaj konstruktor domyslny (bezparametrowy) zaimplementowany w obiekcie (Guest) bo inaczej kaszana
        g = repo.findById2(1L);
        System.out.println(g.getId());
        // Czyli jak odczytujemy obiekt i nie ma go w pamieci podrecznej to hibernet automatycznie sprawdzi czy ma go w bazie


        // Aktualizacja danych
        System.out.println("---------------- UPDATE --------------------------");

        repo.updateAge(g, 35); // Chcemy zmienic pole wiek gosciowi

        //Usuwanie danych
        System.out.println("---------------- REMOVE ---------------------");

        repo.delete(g);
        


        System.out.println("Finish program");
    }

}
