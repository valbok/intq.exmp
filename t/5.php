<?php
/* Enter your code here. Read input from STDIN. Print output to STDOUT */
    
$handle = fopen("php://stdin","r");
$N = fgets($handle);
$NODES = [];
for ($i = 0; $i < $N; $i++) {
    $NODES[$i + 1] = intval(fgets($handle));
}

function good($i) {
    global $NODES;

    // If tail or points to tail node.
    if ($i == 1 or $NODES[$i] == 1 or 
        ($i != $NODES[$i] and good($NODES[$i])))
        return true;

    return false;
}

$k = 0;
for ($i = 2; $i <= $N; $i++) {
    $g = good($i);
    if (!$g) {
        $NODES[$NODES[$i]] = 1;
        $k++;
    }
}

print $k;
