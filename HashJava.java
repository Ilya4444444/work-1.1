import java.util.*;

public class Main {
    public static void main(String[] args) {
        Map<String, Double> prices = new LinkedHashMap<>();
        prices.put("Apple", 0.99);
        prices.put("Bread", 1.50);
        prices.put("Milk", 0.89);
        // Добавляем новый товар
        prices.put("Cheese", 2.50);

        for (Map.Entry<String, Double> entry : prices.entrySet()) {
            System.out.println(entry.getKey() + ": $" + entry.getValue());
        }
    }
}
