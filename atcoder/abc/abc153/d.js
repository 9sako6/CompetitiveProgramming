function main(input) {
  var h = Number(input);
  var cnt = 0;
  while (h > 0) {
    h = Math.floor(h / 2);
    cnt++;
  }
  console.log(Math.pow(2, cnt) - 1);
}
main(require('fs').readFileSync('/dev/stdin', 'utf8'));