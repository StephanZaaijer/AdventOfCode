class Stack:
  def __init__(self, items: str = ""):
    self.items = []
    for item in items:
      self.add( item )
  def __init__(self, item: chr = ''):
    self.items = []
    self.add( item )
  
  def add( self, item: chr ):
    self.items.append( item )

  def add( self, item: str ):
    for i in item:
        self.items.append( i )

  def pop( self, amount: int ):
    temp = "" 
    for i in range(amount):
        temp = self.items.pop() + temp
    return temp

# start order
#  [J]             [F] [M]            
#  [Z] [F]     [G] [Q] [F]            
#  [G] [P]     [H] [Z] [S] [Q]        
#  [V] [W] [Z] [P] [D] [G] [P]        
#  [T] [D] [S] [Z] [N] [W] [B] [N]    
#  [D] [M] [R] [J] [J] [P] [V] [P] [J]
#  [B] [R] [C] [T] [C] [V] [C] [B] [P]
#  [N] [S] [V] [R] [T] [N] [G] [Z] [W]
#   1   2   3   4   5   6   7   8   9 

input = []
with open( "input.txt" ) as inputFile:
  for line in inputFile:
    input.append( line.strip() )

stack1 = Stack( "NBDTVGZJ" )
stack2 = Stack( "SRMDWPF" )
stack3 = Stack( "VCRSZ" )
stack4 = Stack( "RTJZPHG" )
stack5 = Stack( "TCJNDZQF" )
stack6 = Stack( "NVPWGSFM" )
stack7 = Stack( "GCVBPQ" )
stack8 = Stack( "ZBPN" )
stack9 = Stack( "WPJ" )

stackList = [stack1, stack2, stack3, stack4, stack5, stack6, stack7, stack8, stack9]

for line in input:
  data = line.split( ' ' );
  amount = int( data[1] )
  source = int( data[3] )
  destination = int( data[5] )

  sourceStack = stackList[source-1]
  destinationStack = stackList[destination-1]

  destinationStack.add( sourceStack.pop( amount ) );

for stack in stackList:
  print( stack.pop( 1 ), end="" )