import javax.persistence.EntityManager;
import javax.persistence.EntityManagerFactory;
import javax.persistence.EntityTransaction;
import javax.persistence.Persistence;

public class GuestRepository {

    private static EntityManagerFactory factory = Persistence.createEntityManagerFactory("my-persistence-unit");
    private static EntityManager em = factory.createEntityManager();


    public void createNewGuest(String name, int age) {

        System.out.println("Tworze obiekt...");
        // Tworzymy obiekt do zapisania do bazy danych
        Guest newOne = new Guest(name, age);

        System.out.println("Wysylam obiekt...");
        // Entity manager kontroluje zapisywanie do bazy danych wiec musimy go uzyc (wyslac do niego obiekt)
      //  em.persist(newOne);

        // Ogolnie dzieje sie tak ze nasz entitymanager przechowuje te obiekty ktore do niego wysylamy i sobie je ma
        // Jak chcemy je zapisac do bazy danych to trzeba to zrobic przy uzyciu tranzakcji bo np. jak wylacza prad to jest to zabezpieczone

        //Tworzymy tranzakcje
        EntityTransaction transaction = em.getTransaction();

        //Uruchamiamy ja
        transaction.begin();

        //Wysylamy obiekt
        em.persist(newOne);

        //Zamykamy transakcje
        transaction.commit();

        System.out.println("NewGuest ID: " + newOne.getId());

    }

    public Guest findById(long id) {
        return em.find(Guest.class, id);
    }

    public Guest findById2(long id) {
        em.clear();
        return em.find(Guest.class, id);
    }

    public void updateAge(Guest guest, int newAge) {

        // Wykonujemy taka akcje-tranzakcje
        // Otwieramy tranzakcje zmieniamy dane naszych obiektow i zamykamy co spowoduje zpisanie danych w bazie
        EntityTransaction transaction = em.getTransaction();
        transaction.begin();
        guest.setAge(newAge);
        transaction.commit();
    }

    public void delete(Guest guest)
    {
        EntityTransaction transaction = em.getTransaction();
        transaction.begin();
        em.remove(guest);
        transaction.commit();
    }
}














