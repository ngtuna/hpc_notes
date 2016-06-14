# Notes about HPC architectures / systems

## Generic parallel architecture

## Machine models
### 1.a Shared Memory
### 1.b Distributed Shared Memory
### 2.a Distributed Memory
### 2.b Grid-computing
### 2.c Volunteer computing
### 3.a SIMD system
### 3.b Vector machines
### 4 Clusters of SMPs

## Generic Interconnection network

### Bus-based network
### Crossbar network
### Multistage network
### Omega network

## Topologies
### Linear Arrays and Meshes
### Hypercube
#### Operations on Hypercube
![hypercube](images/hypercube.png)
#### One-to-All broadcast
```pascal
procedure ONE_TO_ALL_BC(d, my_id, X)
begin
  mask := 2^d - 1;                      // set all d bits of mask to 1
  for i = d-1 downto 0 do               // each iterator
    mask := mask XOR 2^i;               // set bit i of mask to 0
    if (my_id AND 2^i) == 0 then        // if lower i bits of my_id are 0
      msg_destination := my_id XOR 2^i;
      send X to msg_destination;
    else
      msg_source := my_id XOR 2^i;
      receive X from msg_source;
end
```
#### General One-to-All

## Evaluation criteria of networks

**Diameter** Maximum distance between any two processing nodes in a network.

**Arc Connectivity** Minimum number of links that must be removed to break the network into two disconnected parts.

**Bisection width** Minimum number of communication links that must be removed to partition the network into two equal halves.

**Cost** Number of communication links.

### Static NM
### Dynamic NM
