<!DOCTYPE html>
<html>

<head>
    <meta charset="utf-8">
    <title>提出</title>
    <script type="text/javascript" src="https://ss1.xrea.com/earlgray283c.s1008.xrea.com/enable_tab.js"></script>
    <link rel="stylesheet" type="text/css" href="https://ss1.xrea.com/earlgray283c.s1008.xrea.com/index.css">
</head>

<body>
    <p>結果<br></P>
    <?php
    error_reporting(E_ALL);

    $now_time = time();
    $data = $_POST["sourcecode"];
    $filename = $_POST["userid"] . $now_time . "text.txt";


    $fp = fopen($filename, "a");
    fprintf($fp, "submit\n");
    fprintf($fp, $now_time);
    fprintf($fp, "\n");
    fprintf($fp, $_POST["userid"]);
    fprintf($fp, "\n");
    fprintf($fp, $_POST["contestid"]);
    fprintf($fp, "\n");
    fprintf($fp, $_POST["problem"]);
    fprintf($fp, "\n");
    fprintf($fp, $_POST["language"]);
    fprintf($fp, "\n");
    fwrite($fp, $_POST["sourcecode"]);
    fprintf($fp, "\n");
    fprintf($fp, "end\n");
    fclose($fp);

    $command_str = "./JUDGE.out" . " < " . $_POST["userid"] . $now_time . "text.txt";
    system($command_str);

    $fp_continfo = fopen("./Contests/" . $_POST["contestid"] . "/continfo.txt", "r");
    $start_time = fgets($fp_continfo);
    $end_time = fgets($fp_continfo);
    fclose($fp_continfo);

    //echo "$start_time ? $end_time\n";

    $command_str2 = "./ranking.out" . " 4 " . $_POST["contestid"];

    header('Location: https://ss1.xrea.com/earlgray283c.s1008.xrea.com/Contests/' . $_POST["contestid"] . '/User_Info/' . $now_time . '_' . $_POST["contestid"] . '_' . $_POST["userid"] . '_' . $_POST["problem"] . '.html');
    system($command_str2);
    echo "<br>";
    /*
            $fp3=fopen($_POST["userid"]."testcase.txt", "r");
            while ($line=fgets($fp3)) {
                echo "$line<br>";
            }
            fclose($fp3);
            echo "\n\n";
            $fp2=fopen($_POST["userid"]."log.txt", "r");
             while ($line=fgets($fp2)) {
                 echo "$line<br>";
             }
            fclose($fp2);

              
            echo "<br><br>";
            $fp4=fopen($_POST["userid"]."err.txt", "r");
            while ($line=fgets($fp4)) {
                echo "$line<br>";
            }
            fclose($fp4);
            */
    $tmp = "./show_source.out " . $_POST["contestid"];
    system($tmp);

    system("rm " . $_POST["userid"] . $now_time . "text.txt");
    system("rm " . $_POST["userid"] . "log.txt");
    system("rm " . $_POST["userid"] . "source.txt");
    system("rm " . $_POST["userid"] . "source.c");
    system("rm " . $_POST["userid"] . "testcase.txt");
    system("rm " . $_POST["userid"] . "err.txt");
    system("rm " . "x.txt");
    system("rm " . $_POST["userid"] . ".out");


    ?>


</html>