<?php
if (count($argv) < 2)
{
	echo 'usage: php converter.php <file> [<file>...]'."\n";
	exit;
}

array_shift($argv);

$tiles = [
	'0' => 'EMPTY',
	'Z' => 'W_BABA',
	'G' => 'W_FLAG',
	'K' => 'W_ROCK',
	'I' => 'W_IS',
	'X' => 'W_WIN',
	'P' => 'W_PUSH',
	'V' => 'W_WALL',
	'B' => 'BABA',
	'F' => 'FLAG',
	'R' => 'ROCK',
	'W' => 'WALL',
	'S' => 'W_STOP',
	'Y' => 'W_YOU',
	'O' => 'GOOP',
	'N' => 'W_SINK',
	'U' => 'W_GOOP',
	'Q' => 'W_KILL',
	'A' => 'W_LAVA',
	'L' => 'LAVA',
	'E' => 'W_LOVE',
	'H' => 'LOVE',
	'M' => 'W_SWAP',
	'C' => 'W_EMPTY',
];

foreach ($argv as $filename)
{
	$data = file_get_contents($filename);
	$data = str_replace(array("\n", "\r"), '', $data);

	if (strlen($data) != 130)
	{
		echo $filename." is not a valid level (".strlen($data).")\n";
	}
	else
	{
		$output = 'const uint8_t LEVEL_DATA[] = {'."\n";
		$counter = 1;
		foreach (str_split($data) as $c)
		{
			$t = $tiles[$c];
			$l = strlen($t);
			$output .= $tiles[$c].','.($l < 6 ? str_repeat(' ', 6-$l) : '');

			if (!($counter % 13)) $output .= "\n";
			$counter++;
		}
		$output .= "};\n";
		echo $output;
	}
}
