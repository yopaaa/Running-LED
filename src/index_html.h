const char INDEX_HTML[] PROGMEM = R"rawliteral(
<!DOCTYPE html>
<html>
<head>
  <title>ESP Config</title>
  <meta name='viewport' content='width=device-width, initial-scale=1'>
  <style>
    body { font-family: sans-serif; margin: 20px; line-height: 1.6; color: #333; }
    .container { max-width: 400px; margin: auto; }
    input[type=text], input[type=password] { 
      width: 100%; padding: 8px; margin: 5px 0 15px; box-sizing: border-box; 
    }
    .hidden { display: none; }
    pre { background: #eee; padding: 10px; border-radius: 4px; font-size: 12px; }
    button { 
      width: 100%; padding: 10px; cursor: pointer; border: none; border-radius: 4px; 
      margin-bottom: 10px; font-weight: bold;
    }
    #btnTest { background: #008CBA; color: white; }
    #btnSave { background: #4CAF50; color: white; }
    .card { border: 1px solid #ddd; padding: 15px; border-radius: 8px; box-shadow: 2px 2px 5px #eee; }
  </style>
</head>
<body>
  <div class="container">
    <h2>WiFi Config</h2>
    <div class="card">
      SSID:<input id="ssid" placeholder="Nama WiFi">
      PASS:<input id="pass" type="password" placeholder="Password">
      
      <label><input type="checkbox" id="static" onchange="toggleStatic()"> Gunakan Static IP</label><br><br>
      
      <div id="static_fields" class="hidden">
        IP Address: <input id="ip" value="192.168.1.15">
        Gateway: <input id="gw" value="192.168.1.1">
        Subnet: <input id="sn" value="255.255.255.0">
      </div>

      <button type="button" id="btnTest">Cek Koneksi (Test)</button>
      <button type="button" id="btnSave">Simpan WiFi</button>
      
      <strong>Status:</strong>
      <pre id="out">Ready</pre>
    </div>
  </div>

  <script>
    const out = document.getElementById('out');
    
    function toggleStatic() {
      document.getElementById('static_fields').classList.toggle('hidden', !document.getElementById('static').checked);
    }

    async function sendData(path) {
      out.textContent = 'Memproses...';
      const params = new URLSearchParams();
      params.append('ssid', document.getElementById('ssid').value);
      params.append('pass', document.getElementById('pass').value);
      if(document.getElementById('static').checked) params.append('static', '1');
      params.append('ip', document.getElementById('ip').value);
      params.append('gw', document.getElementById('gw').value);
      params.append('sn', document.getElementById('sn').value);

      try {
        const res = await fetch(path, {
          method: 'POST',
          headers: { 'Content-Type': 'application/x-www-form-urlencoded' },
          body: params
        });
        const d = await res.json();
        
        if (path === '/wifi/test') {
          if (d.ok) {
            out.textContent = `BERHASIL!\nIP: ${d.ip}\nGW: ${d.gw}\nSN: ${d.sn}`;
            // Isi otomatis ke form
            document.getElementById('ip').value = d.ip;
            document.getElementById('gw').value = d.gw;
            document.getElementById('sn').value = d.sn;
          } else {
            out.textContent = 'GAGAL: WiFi tidak ditemukan/salah password';
          }
        } else {
          out.textContent = d.status === 'ok' ? 'Konfigurasi Tersimpan!' : 'Gagal Menyimpan';
        }
      } catch (e) { 
        out.textContent = 'Error: Tidak dapat terhubung ke ESP'; 
      }
    }

    document.getElementById('btnTest').onclick = () => sendData('/wifi/test');
    document.getElementById('btnSave').onclick = () => sendData('/wifi/add');
  </script>
</body>
</html>
)rawliteral";