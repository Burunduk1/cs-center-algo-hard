import sys 

print("<ul>")
for f in sys.stdin.readlines():
  s = f.strip()
  if s <> "":
    print("<li>" + s[2:] + "</li>")
print("</ul>")
