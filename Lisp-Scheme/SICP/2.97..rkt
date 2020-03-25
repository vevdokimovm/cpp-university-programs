#lang racket

;; a
(define (reduce-terms n d)
  (let* ((g-term (gcd-terms n d))
         (c (coeff (first-term g)))
         (o1 (max (order (first-term n))
                  (order (first-term d))))
         (o2 (order (first-term g)))
         (m (expt c (+ 1 o1 (- o2))))
         (nn (div-terms n g-term))
         (dd (div-terms d g-term))
         (coeff-list (append (map (lambda (term) (coeff term)) nn)
                             (map (lambda (term) (coeff term)) dd)))
         (g (gcd-list coeff-list))
         (nnn (map (lambda (term) (make-term (order term)
                                             (/ (coeff term) g))) nn))
         (ddd (map (lambda (term) (make-term (order term)
                                             (/ (coeff term) g))) dd)))
    (list nnn ddd)))

(define (reduce-poly p1 p2)
  (if (same-variable? (variable p1) (variable p2))
      (let ((var (varibale p1))
            (reduced (reduce-terms (term-list p1)
                                   (term-list p2))))
        (list ((make-poly var (car reduced))
               (make-poly var (cadr reduced)))))
      (error "Многочлены от разных переменных -- REDUCE-POLY" (list p1 p2))))

;; b
(define (reduce-integers n d)
  (let ((g (gcd n d)))
    (list (/ n g) (/ d g))))

(define (reduce x) (apply-generic 'reduce x))

(put 'reduce '(polynomial polynomial) reduce-poly)
(put 'reduce '(scheme-number scheme-number) reduce-integers)