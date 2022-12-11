class Monkey:
    # Monkey( std::function<int(int)> operation, int divider, int indexTrue, int indexFalse, std::vector<int> startItems={} ):
    def __init__(self, operation, divider, indexTrue, indexFalse, startItems=None):
        self.operation = operation
        self.divider = divider
        self.indexTrue = indexTrue
        self.indexFalse = indexFalse
        self.items = startItems
        self.inspections = 0

    def run(self, monkeys):
        self.inspections+=len(self.items)
        for item in self.items:
            item = self.operation( item )
            item = int( item / 3 )
            if item % self.divider == 0:
                monkeys[self.indexTrue].add(item)
            else:
                monkeys[self.indexFalse].add(item)
        self.items = []

    def add(self, item):
        self.items.append(item)

monkeys = [];

# # Test values
# monkeys.append( Monkey( lambda worryLevel: worryLevel * 19, 23, 2, 3, [79, 98] ) )
# monkeys.append( Monkey( lambda worryLevel: worryLevel + 6, 19, 2, 0, [54, 65, 75, 74] ) )
# monkeys.append( Monkey( lambda worryLevel: worryLevel*worryLevel, 13, 1, 3, [79, 60, 97] ) )
# monkeys.append( Monkey( lambda worryLevel: worryLevel + 3, 17, 0, 1, [74] ) )


monkeys.append( Monkey( lambda worryLevel: worryLevel * 3, 13, 6, 2, [ 89, 73, 66, 57, 64, 80 ] ) );
monkeys.append( Monkey( lambda worryLevel: worryLevel + 1, 3, 7, 4, [ 83, 78, 81, 55, 81, 59, 69 ] ) );
monkeys.append( Monkey( lambda worryLevel: worryLevel * 13, 7, 1, 4, [ 76, 91, 58, 85 ] ) );
monkeys.append( Monkey( lambda worryLevel: worryLevel * worryLevel, 2, 6, 0, [ 71, 72, 74, 76, 68 ] ) );
monkeys.append( Monkey( lambda worryLevel: worryLevel + 7, 19, 5, 7, [ 98, 85, 84 ] ) );
monkeys.append( Monkey( lambda worryLevel: worryLevel + 8, 5, 3, 0, [ 78 ] ) );
monkeys.append( Monkey( lambda worryLevel: worryLevel + 4, 11, 1, 2, [ 86, 70, 60, 88, 88, 78, 74, 83 ] ) );
monkeys.append( Monkey( lambda worryLevel: worryLevel + 5, 17, 3, 5, [ 81, 58 ] ) );

for i in range(20):
    for monkey in monkeys:
        monkey.run(monkeys)
    
results = []
for monkey in monkeys:
    results.append( monkey.inspections )
results.sort()
print( results[ len(results) - 2 ] * results[ len(results) - 1 ]  )
