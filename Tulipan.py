import turtle as tu
import re
import docx

data = docx.Document("tulipanes.docx")
coordinates = []
colour = []

# Recorrer cada párrafo en el documento
for para in data.paragraphs:
    try:
        # Patrón para encontrar coordenadas (x, y)
        coord_pattern = r'[-+]?\d*\.\d*(?:[eE][-+]?\d+)'
        coord_stg_tup = re.findall(r'\(' + coord_pattern + r', ?' + coord_pattern + r'\)', para.text)
        coord_num_tup = [tuple(map(float, re.findall(coord_pattern, c))) for c in coord_stg_tup]
        
        # Patrón para encontrar colores (r, g, b)
        color_pattern = r'\(' + coord_pattern + r', ?' + coord_pattern + r', ?' + coord_pattern + r'\)'
        color_stg_tup = re.findall(color_pattern, para.text)
        color_val_lst = [tuple(map(float, re.findall(coord_pattern, c))) for c in color_stg_tup]
        
        coordinates.append(coord_num_tup)
        colour.append(color_val_lst)
    except Exception as e:
        print("Error:", e)

# Configuración de Turtle
pen = tu.Turtle()
screen = tu.Screen()
screen.setup(width=800, height=600)  # Configurar tamaño de la pantalla

tu.tracer(2)
pen.speed(10)

for i in range(len(coordinates)):
    draw = True
    path = coordinates[i]
    col = colour[i]

    pen.color(*col)
    pen.begin_fill()

    for x, y in path:
        y = -y  # Invertir eje y para que sea coherente con la pantalla
        if draw:
            pen.up()
            pen.goto(x, y)
            pen.down()
            draw = False
        else:
            pen.goto(x, y)
    
    pen.end_fill()

pen.hideturtle()
screen.mainloop()
