<?php
/*
 * Complete the function below.
 */
function numOfPlaylist( $N,  $K,  $L) {
    $list = [];
    $rec = function ($p = [], $depth = 0) use ($L, $N, $K, &$list, &$rec) {
        if ($depth >= $L) {
            $list[] = $p;
            return;
        }

        for ($song = 0; $song < $N; $song++) {
            $s = $p;
            $s[] = $song;
            $rec($s, $depth + 1);
        }
    };

    $rec();

    $res = [];
    // Looking for duplicates.
    foreach ($list as $key => $items) {
        $k = 0;        
        for ($i = 0; $i < count($items); $i++) {
            for ($j = $i + 1; $j < count($items); $j++) {
                if ($items[$i] == $items[$j]) {
                    $k++;                
                }
            }
        }
        if ($k < $K or $K == 0) {
            $res[] = $items;
        }
    }

    return count($res);
}

   
$__fp = fopen("php://stdin", "r");
fscanf($__fp, "%d", $_N);
fscanf($__fp, "%d", $_K);
fscanf($__fp, "%d", $_L);

$res = numOfPlaylist($_N, $_K, $_L);
print $res;
?>
