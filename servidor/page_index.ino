void send_page_index() {
server.send(200, "text/html", R"=====(

<!DOCTYPE html>
<html>
  <head>
    <meta http-equiv="Content-Type" content="text/html;charset=utf-8"/>
    <meta name="viewport" content="width=device-width, initial-scale=1, maximum-scale=1, user-scalable=0" />
    <meta charset="UTF-8" />
    <title>CEMEC Carrinho</title>
    <style>
    
      body {
        width: 100%;
        height: 100%;
        position: absolute;
        top: 0;
        left: 0;
        overflow: hidden;
        background-color: black;
        color: white;
        display: grid;
        grid-template-columns: 1fr 1fr 1fr;
        grid-template-rows: 1fr 1fr 1fr;
        margin: 0;
      }
      button {
        width: 100%;
        height: 100%;
        background: white;
        color: black;
        border: none;
        border-radius: 0;
      }
      #btn1 { grid-area: 1 / 2 }
      #btn2 { grid-area: 2 / 1 }
      #btn3 { grid-area: 2 / 3 }
      #btn4 { grid-area: 3 / 2 }
      
    </style>
  </head>
  <body>
  
    <button id="btn1"></button>
    <button id="btn2"></button>
    <button id="btn3"></button>
    <button id="btn4"></button>
    
    <script>
    
      initializeButton("btn1", [1,0,1,0])
      initializeButton("btn1", [1,0,0,1])
      initializeButton("btn1", [0,1,1,0])
      initializeButton("btn1", [0,1,0,1])
      
      function initializeButton(id, res) {
        document.getElementById(id).addEventListener("click", async _ => {
          await fetch(`/0_${res[0]}`, { method: "post" })
          await fetch(`/1_${res[1]}`, { method: "post" })
          await fetch(`/2_${res[2]}`, { method: "post" })
          await fetch(`/3_${res[3]}`, { method: "post" })
        })
      }
      
    </script>
  </body>
</html>

)=====");
}
