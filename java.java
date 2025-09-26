import java.util.ArrayList;

public class Main {
    public static void main(String[] args) {
        ArrayList<String> list = new ArrayList<>();
        
        list.add("Привет");
        list.add("Мир");
        
        System.out.println(list); // [Привет, Мир]
        System.out.println(list.get(1)); // Мир
    }
}
