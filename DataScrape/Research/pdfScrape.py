import pdfplumber

pdf_path = "togidk-k24.pdf"
with pdfplumber.open(pdf_path) as pdf:
    #for page in pdf.pages:
    #    print(page.extract_text())
    print(pdf.pages[7].extract_text())

    