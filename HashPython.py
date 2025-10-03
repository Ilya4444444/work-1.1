def main():
    prices = {
        "Apple": 0.99,
        "Bread": 1.50,
        "Milk": 0.89
    }
    # Добавляем новый товар
    prices["Cheese"] = 2.50

    for item, price in prices.items():
        print(f"{item}: ${price:.2f}")

if __name__ == "__main__":
    main()
