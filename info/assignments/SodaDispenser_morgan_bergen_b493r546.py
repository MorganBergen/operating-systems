class SodaDispenser:
    def __init__(self):
        """Initialize soda dispenser."""
        self.stack = []

    def add_soda(self, soda):
        """
        Add a soda to the top of the dispenser.
        
        Arguments are soda (str): The name of the soda to add.
        """
        self.stack.append(soda)
        print(f"{soda} added to the dispenser.")

    def dispense_soda(self):
        """
        Remove and return the soda from the top of the dispenser.
        """
        if self.is_empty():
            raise Exception("Dispenser is empty! Cannot dispense soda.")
        soda = self.stack.pop()
        print(f"{soda} dispensed.")
        return soda

    def is_empty(self):
        """
        Check if the dispenser is empty.
        """
        return len(self.stack) == 0

    def peek_soda(self):
        """
        View the soda at the top of the dispenser without removing it.
        """
        if self.is_empty():
            raise Exception("Dispenser is empty! No soda to peek.")
        return self.stack[-1]

# Test case
def test_soda_dispenser():
    dispenser = SodaDispenser()
    
    # Test is_empty on a new dispenser
    assert dispenser.is_empty() == True, "Test failed: Dispenser should be empty initially"
    
    # Test add_soda and peek_soda
    dispenser.add_soda("Coke")
    assert dispenser.peek_soda() == "Coke", "Test failed: Top soda should be Coke"
    
    dispenser.add_soda("Sprite")
    assert dispenser.peek_soda() == "Sprite", "Test failed: Top soda should be Sprite"
    
    # Test dispense_soda
    assert dispenser.dispense_soda() == "Sprite", "Test failed: Should have dispensed Sprite."
    assert dispenser.peek_soda() == "Coke", "Test failed: Top soda should be Coke after dispensing Sprite."
    
    # Test dispenser emptiness after dispensing all sodas
    dispenser.dispense_soda()
    assert dispenser.is_empty() == True, "Test failed: Dispenser should be empty after all sodas dispensed."
    
    # Test edge case: dispense from an empty dispenser
    try:
        dispenser.dispense_soda()
    except Exception as e:
        print(e)  

test_soda_dispenser()

