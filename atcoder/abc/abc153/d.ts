function main(input) {
  let h = Number(input);
  let cnt = 0;
  while (h > 0) {
    h = Math.floor(h / 2);
    cnt++;
  }
  console.log(2 ** cnt - 1);
}
main(require('fs').readFileSync('/dev/stdin', 'utf8'));