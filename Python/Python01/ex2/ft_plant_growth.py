#!/usr/bin/python3
class Plant:
    def __init__(self, name: str, height: int, age: int) -> None:
        self.name = name
        self.height = height
        self.age_att = age

    def get_info(self) -> None:
        print(f"{self.name}: {self.height}cm, {self.age_att} days old")

    def grow(self, ammount: int = 1) -> None:
        self.height = self.height + ammount

    def age(self, ammount: int = 1) -> None:
        self.age_att = self.age_att + ammount


if __name__ == "__main__":
    rose = Plant("Rose", 25, 30)
    tulip = Plant("Tulip", 15, 20)
    start_height = rose.height
    print("=== Day 1 ===")
    rose.get_info()
    for _ in range(6):
        rose.grow(1)
        rose.age(1)
        tulip.grow(2)
        tulip.age(1)
    print("=== Day 7 ===")
    rose.get_info()
    growth_this_week = rose.height - start_height
    print(f"Growth this week: +{growth_this_week}cm")
